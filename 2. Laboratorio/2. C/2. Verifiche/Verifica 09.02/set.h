#ifndef SET_H
#define SET_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    Set *emptySet = (Set *)malloc(sizeof(Set));
    // Set *emptySet = (Set *)malloc(sizeof(Set *)); // no (-0.5) --> La size di un puntatore è sempre la stessa, indipendentemente dal tipo a cui punta, quindi sizeof(Set *) è errato in questo contesto.
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
    // Check 1: verifica se l'input è valido
    // Se il set è nullo non possiamo clonarlo --> return error
    if (!set)
    {
        return NULL;
    }

    Set *newSet = createEmptySet();

    // Check 2: verifica l'allocazione della memoria per il nuovo set
    // Se la malloc fallisce --> return error
    if (!newSet)
    {
        return NULL;
    }

    Node *current = set->first;
    Node *last = NULL;

    while (current)
    {
        Node *cloned = cloneNode(current);

        // Check 3: verifica la clonazione della memoria allocata
        // Se cloneNode fallisce dobbiamo liberare tutta la memoria allocata per evitare memory leaks
        if (!cloned)
        {
            Node *temp = newSet->first;
            while (temp)
            {
                Node *next = temp->next;
                destroyNode(temp);
                temp = next;
            }

            free(newSet);
            return NULL;
        }

        // Se questo è il primo nodo, lo si assegna al nuovo set
        if (!newSet->first)
        {
            newSet->first = cloned;
        }
        else
        {
            // Altrimenti lo colleghi al nodo clonato precedentemente
            last->next = cloned;
        }

        last = cloned;
        current = current->next;
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
    if (!set)
    {
        return -1;
    }

    Node *current = set->first;
    while (current)
    {
        Node *next = current->next;
        destroyNode(current);
        current = next;
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
    if (!set)
    {
        return -1;
    }

    int count = 0;
    Node *current = set->first;

    while (current)
    {
        count++;
        current = current->next;
    }

    return count;
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
    if (!set || !value)
    {
        return false;
    }

    Node *current = set->first;

    while (current)
    {
        if (strcmp(current->value, value) == 0) // firstNode->value == value non funziona per stringhe, bisogna usare strcmp (-0.5)
        {
            return true;
        }

        current = current->next;
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

// Implementazione precedente errata
int insertNodeInSet(Set *set, char *value, int index)
{
    if (!set || !value || index < 0)
    {
        return -1;
    }

    if (setContains(set, value))
    {
        return -1;
    }

    Node *newNode = createNode(value);
    if (!newNode)
    {
        return -1;
    }

    if (index == 0)
    {
        newNode->next = set->first;
        set->first = newNode;
        return 0;
    }

    Node *current = set->first;
    int i = 0;

    while (current && i < index - 1)
    {
        current = current->next;
        i++;
    }

    if (!current)
    {
        destroyNode(newNode);
        return -1;
    }

    newNode->next = current->next;
    current->next = newNode;

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
    if (!set || index < 0 || !set->first)
    {
        return NULL;
    }

    Node *current = set->first;

    if (index == 0)
    {
        set->first = current->next;
        char *value = current->value;
        free(current);
        return value;
    }

    int i = 0;
    while (current->next && i < index - 1)
    {
        current = current->next;
        i++;
    }

    if (!current->next)
    {
        return NULL;
    }

    Node *toRemove = current->next;
    current->next = toRemove->next;

    char *value = toRemove->value;
    free(toRemove);

    return value;
}

/**
 * printSet prints the values of each node in the set, one per line.
 *
 * @param set The set to print
 */
void printSet(Set *set)
{
    if (!set)
    {
        return;
    }

    Node *current = set->first;

    while (current)
    {
        printf("%s\n", current->value);
        current = current->next;
    }
}

#endif
