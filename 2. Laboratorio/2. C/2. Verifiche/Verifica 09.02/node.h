#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node represents a list node, wrapping a string value
typedef struct Node
{
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
Node *createNode(char *value)
{
    if (!value)
    {
        return NULL;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        return NULL;
    }

    newNode->value = strdup(value); // Mancava strdup
    if (!newNode->value)
    {
        free(newNode);
        return NULL;
    }

    newNode->next = NULL;

    return newNode;
}

/**
 * cloneNode creates a new Node entity by cloning another one value.
 *
 * @param node The node to clone, must not be NULL.
 *
 * @returns The cloned Node, or NULL in case of any error.
 */
Node *cloneNode(Node *node)
{
    if (!node)
    {
        return NULL;
    }

    Node *clonedNode = (Node *)malloc(sizeof(Node));
    if (!clonedNode)
    {
        return NULL;
    }

    clonedNode->value = strdup(node->value);
    if (!clonedNode->value)
    {
        free(clonedNode);
        return NULL;
    }

    clonedNode->next = NULL;

    return clonedNode;
}

/**
 * destroyNode deallocates a Node entity resources.
 *
 * @param node The node to destroy, must not be NULL.
 *
 * @returns 0 if successful, -1 on any error.
 */
int destroyNode(Node *node)
{
    if (!node)
    {
        return -1;
    }
    /*
    no (-0.5)
    if (node->next)
    {
        free(node->next);
    }
    */

    if (node->value)
    {
        free(node->value);
    }

    free(node);

    return 0;
}

#endif
