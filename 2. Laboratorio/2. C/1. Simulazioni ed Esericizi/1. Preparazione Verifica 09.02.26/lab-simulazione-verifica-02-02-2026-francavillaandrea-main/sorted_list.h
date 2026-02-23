#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "node.h"

typedef struct
{
    Node *first;
} SortedList;

/**
 * createEmptySortedList creates a new SortedList entity with no first node
 * (empty list).
 *
 * @returns The created SortedList, or NULL in case of any error.
 */
SortedList *createEmptySortedList()
{
    SortedList *list = (SortedList *)malloc(sizeof(SortedList));

    if (!list)
    {
        return NULL;
    }

    list->first = NULL;

    return list;
}

/**
 * cloneSortedList creates a new SortedList entity by cloning another list
 * nodes.
 *
 * @param list The sorted list to clone, must not be NULL.
 *
 * @returns The cloned SortedList, or NULL in case of any error.
 */
SortedList *cloneSortedList(SortedList *list)
{
    if (!list)
    {
        return NULL;
    }

    SortedList *clonedList = createEmptySortedList();

    if (!clonedList)
    {
        return NULL;
    }

      clonedList->first = cloneNode(list->first);

    if (!clonedList->first)
    {
        free(clonedList);
        return NULL;
    }

    Node *current = list->first->next;
    Node *clonedCurrent = clonedList->first;

    while (current)
    {
        clonedCurrent->next = cloneNode(current);
        clonedCurrent = clonedCurrent->next;
        current = current->next;
    }

    return clonedList;
}

/**
 * destroySortedList deallocates a SortedList entity resources.
 *
 * @param list The list to destroy, must not be NULL.
 *
 * @returns 0 if successful, -1 on any error.
 */
int destroySortedList(SortedList *list)
{
    if (!list)
    {
        return -1;
    }

    Node *current = list->first;

    while (current)
    {
        Node *next = current->next;

        if (destroyNode(current) != 0)
        {
            return -1;
        }

        current = next;
    }

    free(list);
    return 0;
}

/**
 * getSortedListSize gets the size of the list, in terms of number of nodes.
 *
 * @param list The list to get size from.
 *
 * @returns The number of nodes in the list, or -1 in case of any error.
 */
int getSortedListSize(SortedList *list)
{
    if (!list)
    {
        return -1;
    }

    int size = 0;
    Node *current = list->first;

    while (current)
    {
        size++;
        current = current->next;
    }

    return size;
}

/**
 * sortedListContains tells if the specified sorted list contains a node with
 * the specified value. It must be optimized, since the list is sorted.
 *
 * @param list The list to scan.
 *
 * @param value The value to search for.
 *
 * @returns true if the list contains the value, false otherwise.
 */
bool sortedListContains(SortedList *list, char *value)
{
    if (!list || !value)
    {
        return false;
    }

    Node *current = list->first;

    while (current)
    {
        int cmp = strcmp(current->value, value);
        if (cmp == 0)
        {
            return true;
        }
        if (cmp > 0)
        {
            return false;
        }
        current = current->next;
    }

    return false;
}

/**
 * insertNode inserts a new node in the sorted list, at the right index, by
 * right-shifting the subsequents.
 *
 * @param list The list to scan.
 *
 * @param element The element to add.
 *
 * @returns 0 if successful, -1 on any error.
 */
int insertNodeInSortedList(SortedList *list, char *value)
{
    if (!list || !value)
    {
        return -1;
    }

    Node *newNode = createNode(value);
    if (!newNode)
    {
        return -1;
    }

    if (!list->first || strcmp(value, list->first->value) < 0)
    {
        newNode->next = list->first;
        list->first = newNode;
        return 0;
    }

    Node *current = list->first;
    while (current->next && strcmp(value, current->next->value) > 0)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return 0;
}

/**
 * removeNodeFromSortedList removes a Node from the specified list at the
 * specified index, left-shifting the subsequent nodes.
 *
 * @param list The list to scan.
 *
 * @returns The removed node if successfull, NULL on any error.
 */
Node *removeNodeFromSortedList(SortedList *list, int index)
{
    if (!list || index < 0)
    {
        return NULL;
    }

    Node *removed = NULL;

    if (index == 0)
    {
        removed = list->first;
        list->first = list->first->next;
        return removed;
    }

    Node *current = list->first;
    int currentIndex = 0;

    while (current && currentIndex < index - 1)
    {
        current = current->next;
        currentIndex++;
    }

    if (!current || !current->next)
    {
        return NULL;
    }

    removed = current->next;
    current->next = removed->next;

    return removed;
}

/**
 * printSortedList prints the values of each node in the list, one per line.
 *
 * @param list The list to print
 */
void printSortedList(SortedList *list)
{
}

#endif
