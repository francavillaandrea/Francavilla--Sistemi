#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <stdbool.h>
#include <stdio.h>

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

  if (list == NULL)
  {
    return NULL;
  }

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
  if (list == NULL)
  {
    return NULL;
  }

  SortedList *newList = createEmptySortedList();
  if (newList == NULL)
  {
    return NULL;
  }

  if (list->first == NULL)
  {
    return newList;
  }

  newList->first = cloneNode(list->first);

  Node *original = list->first;
  Node *temp = newList->first;

  while (original->next != NULL)
  {
    temp->next = cloneNode(original->next);

    temp = temp->next;
    original = original->next;
  }

  return newList;
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
  if (list == NULL)
  {
    return -1;
  }

  if (list->first == NULL)
  {
    free(list);
    return 0;
  }

  Node *temp = list->first;
  Node *temp2;
  while (temp != NULL)
  {
    temp2 = temp->next;
    destroyNode(temp);
    temp = temp2;
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
  if (list == NULL)
  {
    return -1;
  }

  if (list->first == NULL)
  {
    return 0;
  }

  Node *original = list->first;

  int cont = 1;
  while (original->next != NULL)
  {
    cont++;
    original = original->next;
  }

  return cont;
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
  if (list == NULL || value == NULL)
  {
    return false;
  }

  if (list->first == NULL)
  {
    return false;
  }

  Node *original = list->first;

  while (original->next != NULL)
  {
    if (original->value == value)
    {
      return true;
    }
    original = original->next;
  }
  if (original->value == value)
  {
    return true;
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
  if (list == NULL || value == NULL)
  {
    return -1;
  }

  if (list->first == NULL)
  {
    list->first = createNode(value);
    return 0;
  }

  if (list->first->next == NULL)
  {
    if (value < list->first->value)
    {
      Node *temp = list->first;
      list->first = createNode(value);
      list->first->next = temp;
    }
    else
    {
      list->first->next = createNode(value);
    }
    return 0;
  }

  Node *prior = list->first;
  Node *temp = list->first->next;
  bool switched = false;
  do
  {
    if (value < temp->value)
    {
      prior->next = createNode(value);
      prior->next->next = temp;
      switched = true;
      break;
    }

    prior = temp;
    temp = temp->next;
  } while (temp != NULL);

  if (!switched)
  {
    prior->next = createNode(value);
  }

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
  if (list == NULL)
  {
    return NULL;
  }

  if (list->first == NULL)
  {
    return NULL;
  }

  if (index == 0)
  {
    Node *temp = list->first;
    list->first = list->first->next;
    return temp;
  }

  Node *prior = list->first;

  int cont = 0;
  while (prior->next != NULL)
  {
    cont++;
    if (cont == index)
    {
      Node *temp = prior->next;
      prior->next = prior->next->next;
      return temp;
    }
    prior = prior->next;
  }

  return NULL;
}

/**
 * printSortedList prints the values of each node in the list, one per line.
 *
 * @param list The list to print
 */
void printSortedList(SortedList *list)
{
  if (list == NULL)
  {
    return;
  }

  if (list->first == NULL)
  {
    return;
  }

  Node *original = list->first;

  while (original != NULL)
  {
    printf("%c\n", original->value);
    original = original->next;
  }
}

#endif
