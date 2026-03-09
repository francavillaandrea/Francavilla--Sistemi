#ifndef SET_H
#define SET_H

#include <stdbool.h>
#include <stdio.h>

#include "node.h"

typedef struct
{
    Node *first;
} Set;

/**
 * createEmptySet creates a new Set entity with no first node
 * (empty set).
 *
 * @returns The created Set, or NULL in case of any error.
 */
Set *createEmptySet()
{
    // implement function logic here...
    Set *emptySet = (Set *)malloc(sizeof(Set *)); // no (-0.5)
    if (!emptySet)
    {
        return NULL;
    }
    emptySet->first = NULL;
    return emptySet;
}

/**
 * cloneSet creates a new Set entity by cloning another set
 * nodes.
 *
 * @param set The sorted set to clone, must not be NULL.
 *
 * @returns The cloned Set, or NULL in case of any error.
 */
Set *cloneSet(Set *set)
{
    // implement function logic here...
    if (!set)
    {
        return NULL;
    }
    Set *newSet = createEmptySet();
    // manca check (-0)
    if (!newSet)
    {
        return NULL;
    }
    if (!set->first)
    {
        return newSet;
    }

    Node *firstNode = set->first;
    Node *temp = newSet->first;
    newSet->first = cloneNode(set->first);
    // manca check (-0.5)
    while (firstNode->next)
    {
        temp->next = cloneNode(firstNode->next);
        // manca check (-0)
        temp = temp->next;
        firstNode = firstNode->next;
    }
    return newSet;
}

/**
 * destroySet deallocates a Set entity resources.
 *
 * @param set The set to destroy, must not be NULL.
 *
 * @returns 0 if successful, -1 on any error.
 */
int destroySet(Set *set)
{
    // implement function logic here...
    if (!set)
    {
        return -1;
    }

    if (!set->first)
    {
        free(set);
        return 0;
    }

    Node *temp = set->first;
    Node *temp2;
    while (temp)
    {
        temp2 = temp->next;
        destroyNode(temp);
        temp = temp2;
    }

    free(set);
    return 0;
}

/**
 * getSetSize gets the size of the set, in terms of number of nodes.
 *
 * @param set The set to get size from.
 *
 * @returns The number of nodes in the set, or -1 in case of any error.
 */
int getSetSize(Set *set)
{
    // implement function logic here...
    if (!set)
    {
        return -1;
    }

    if (!set->first)
    {
        return 0;
    }

    Node *firstNode = set->first;

    int cont = 1;
    while (firstNode->next)
    {
        cont++;
        firstNode = firstNode->next;
    }

    return cont;
}

/**
 * setContains tells if the specified set contains a node with
 * the specified value.
 *
 * @param set The set to scan.
 *
 * @param value The value to search for.
 *
 * @returns true if the set contains the value, false otherwise.
 */
bool setContains(Set *set, char *value)
{
    // implement function logic here...
    if (!set || !value)
    {
        return false;
    }

    if (!set->first)
    {
        return false;
    }

    Node *firstNode = set->first;

    while (firstNode->next)
    {
        if (firstNode->value == value) // ci va strcmp (-0.5)
        {
            return true;
        }
        firstNode = firstNode->next;
    }
    if (firstNode->value == value) // non serve (-0.5)
    {
        return true;
    }

    return false;
}

/**
 * insertNode inserts a new node in the set, at the specified index, by
 * right-shifting the subsequents. If the element is already present, it returns
 * as an error.
 *
 * @param set The set to scan.
 *
 * @param value The element to add.
 *
 * @param index The index in which insert the element into
 *
 * @returns 0 if successful, -1 if the element is present or any error.
 */
int insertNodeInSet(Set *set, char *value, int index)
{
    // implementazione errata (-0)
    // implement function logic here...
    if (!set || !value)
    {
        return -1;
    }

    if (!set->first)
    {
        set->first = createNode(value);
        // manca check (-0.5)
        return 0;
    }

    if (!set->first->next)
    {
        if (value < set->first->value) // ci va strcmp (-0.5)
        {
            Node *temp = set->first;
            set->first = createNode(value);
            // manca check (-0)
            set->first->next = temp;
        }
        else
        {
            set->first->next = createNode(value);
            // manca check (-0)
        }
        return 0;
    }

    Node *prior = set->first;
    Node *temp = set->first->next;
    bool switched = false;
    do
    {
        if (value < temp->value) // ci va strcmp (-0.5)
        {
            prior->next = createNode(value);
            // manca check (-0)
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
        // manca check (-0)
    }

    return 0;
}

/**
 * removeNodeFromSet removes a Node from the specified set at the
 * specified index, left-shifting the subsequent nodes.
 *
 * @param set The set to scan.
 *
 * @returns The removed node value if successfull, NULL on any error.
 */
char *removeNodeFromSet(Set *set, int index)
{
    // implement function logic here...
    if (!set)
    {
        return NULL;
    }

    if (!set->first)
    {
        return NULL;
    }

    if (index == 0)
    {
        Node *temp = set->first;
        set->first = set->first->next;
        return temp;
    }

    Node *currentNode = set->first;

    int cont = 0;
    while (currentNode->next)
    {
        cont++;
        if (cont == index) // ci va strcmp (-0.5)
        {
            Node *temp = currentNode->next;
            currentNode->next = currentNode->next->next;
            return temp;
        }
        currentNode = currentNode->next;
    }

    return NULL;
}

/**
 * printSet prints the values of each node in the set, one per line.
 *
 * @param set The set to print
 */
void printSet(Set *set)
{
    // implement function logic here...
    if (!set)
    {
        return;
    }

    if (!set->first)
    {
        return;
    }

    Node *currentNode = set->first;

    while (currentNode)
    {
        printf("%\n", currentNode->value);
        currentNode = currentNode->next;
    }
}
#endif
