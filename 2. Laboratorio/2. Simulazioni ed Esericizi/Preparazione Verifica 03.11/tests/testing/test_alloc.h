#ifndef TEST_ALLOC_H
#define TEST_ALLOC_H

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

// PROTOTYPES

/**
 * testMalloc is a mock of the malloc function that allows to test
 * dynamic allocation behaviors.
 *
 * @see malloc
 */
void *testMalloc(size_t size);

/**
 * testFree is a mock of the free function that allows to test
 * dynamic allocation behaviors.
 *
 * @see free
 */
void testFree(void *ptr);

/**
 * isAllocated returns true if the memory area pointed by ptr is allocated
 * by malloc or not. It is mainly used to test memory allocations in a program
 * and works only if malloc and free have been mocked with test_malloc and
 * test_free.
 *
 * @param ptr The pointer to check
 *
 * @returns True if the memory area pointed is allocated via malloc, False
 * otherwise.
 *
 * @see testMalloc
 *
 * @see testFree
 */
bool isAllocated(const void *ptr);

#endif