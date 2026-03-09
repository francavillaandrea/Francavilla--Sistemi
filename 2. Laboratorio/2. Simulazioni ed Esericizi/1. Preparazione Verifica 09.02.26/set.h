#ifndef SET_H
#define SET_H

#include "node.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  Node *first;
} Set;

/**
 * createEmptySet creates a new Set entity with no first node
 * (empty set).
 *
 * @returns The created Set, or NULL in case of any error.
 */
Set *createEmptySet() {
  Set *setVuoto = (Set *)malloc(sizeof(Set *));
  if (setVuoto == NULL) {
    return NULL;
  }
  setVuoto->first = NULL;
  return setVuoto;
}

/**
 * cloneSet creates a new Set entity by cloning another set
 * nodes.
 *
 * @param set The sorted set to clone, must not be NULL.
 *
 * @returns The cloned Set, or NULL in case of any error.
 */
Set *cloneSet(Set *set) {
  if (set == NULL) {
    return NULL;
  }
  Set *clonedSet = createEmptySet();
  if (clonedSet == NULL) {
    return NULL;
  }
  if (set->first == NULL) {
    return clonedSet;
  }
  Node *current = clonedSet->first;
  Node *previous = NULL;
  while (current != NULL) {
    Node *newNode = createNode(current->value);
    if (newNode == NULL) {
      return NULL;
    }
    if (previous == NULL) // se siamo al primo
    {
      clonedSet->first = newNode;
    } else {
      previous->next = newNode;
    }
    current = current->next;
    previous = previous->next;
  }
  return clonedSet;
}

/**
 * destroySet deallocates a Set entity resources.
 *
 * @param set The set to destroy, must not be NULL.
 *
 * @returns 0 if successful, -1 on any error.
 */
int destroySet(Set *set) {
  if (set == NULL) {
    return -1;
  }
  Node *it = set->first;
  while (it != NULL) {
    Node *next = it->next;
    destroyNode(it);
    it = it->next;
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
int getSetSize(Set *set) {
  if (set == NULL) {
    return -1;
  }
  int count = 0;
  Node *it = set->first;
  while (it != NULL) {
    Node *next = it->next;
    count++;
    it = it->next;
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
bool setContains(Set *set, char *value) {
  if (set == NULL || value == NULL) {
    return false;
  }
  Node *it = set->first;
  while (it != NULL) {
    int cmp = strcmp(value, it->value);
    if (cmp == 0) {
      return true;
    }
    it = it->next;
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
int insertNodeInSet(Set *set, char *value, int index) {
  if (set == NULL || value == NULL || index < 0) {
    return -1;
  }
  Node *current = set->first;
  if (set->first == NULL) {
    current->value = value;
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
char *removeNodeFromSet(Set *set, int index) {
  // implement function logic here...
  return NULL;
}

/**
 * printSet prints the values of each node in the set, one per line.
 *
 * @param set The set to print
 */
void printSet(Set *set) {
  if (set == NULL) {
    return NULL;
  }
  Node *it = set->first;
  while (it != NULL) {
    Node *next = it->next;
    printf("%s\n", it->value);
    it = it->next;
  }
  return 0;
}

#endif
