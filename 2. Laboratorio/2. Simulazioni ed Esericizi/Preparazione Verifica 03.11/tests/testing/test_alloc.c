#include "test_alloc.h"

#undef malloc
#undef free

#define MAX_ALLOCATED 100

static void *allocated[MAX_ALLOCATED];
static unsigned int currently_allocated = 0;

/**
 * testMalloc is a mock of the malloc function that allows to test
 * dynamic allocation behaviors.
 *
 * @see malloc
 */
void *testMalloc(size_t size) {
  if (currently_allocated == MAX_ALLOCATED) {
    puts("Cannot malloc: no more memory left\n");
    return NULL;
  }

  void *ptr = malloc(size);

  allocated[currently_allocated++] = ptr;

  return ptr;
}

/**
 * testFree is a mock of the free function that allows to test
 * dynamic allocation behaviors.
 *
 * @see free
 */
void testFree(void *ptr) {
  if (currently_allocated == 0 || ptr == NULL) {
    puts("Cannot free(ptr): nothing allocated\n");
  } else {
    int last_allocated = currently_allocated - 1;
    for (int i = last_allocated; i >= 0; i--) {
      if (ptr == allocated[i]) {
        allocated[i] = NULL;

        allocated[i] = allocated[last_allocated];

        currently_allocated--;
        break;
      }
    }

    free(ptr);
  }
}

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
bool isAllocated(const void *ptr) {
  int ca = currently_allocated;
  for (int i = 0; i < currently_allocated; i++) {
    void *all = allocated[i];
    if (ptr == allocated[i]) {
      return true;
    }
  }

  return false;
}

