#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Node represents a list node, wrapping a string value
typedef struct Node {
  char *value;
  struct Node *next;
} Node;

/**
 * createNode creates a new Node entity.
 *
 * @param value The wrapped value of the Node.
 *
 * @returns The created Node, or NULL in case of any error.
 */
Node *createNode(char *value) {
    if(value==NULL)
    {
        return NULL;
    }
  Node *newNode=(Node*)malloc(sizeof(Node*));
  if(newNode==NULL)
  {
      return NULL;
  }
  newNode->value=(char*)malloc(sizeof(char*));
  newNode->value=strdup(value);
  return newNode;
}

/**
 * cloneNode creates a new Node entity by cloning another one value.
 *
 * @param node The node to clone, must not be NULL.
 *
 * @returns The cloned Node, or NULL in case of any error.
 */
Node *cloneNode(Node *node) {
    if(node==NULL)
    {
        return NULL;
    }
    return createNode(node->value);
}

/**
 * destroyNode deallocates a Node entity resources.
 *
 * @param node The node to destroy, must not be NULL.
 *
 * @returns 0 if successful, -1 on any error.
 */
int destroyNode(Node *node) {
    if(node==NULL)
    {
        return -1;
    }
    free(node->value);
    free(node);
    return 0;
}

#endif
