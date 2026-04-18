#ifndef TEST_MOCKS_H
#define TEST_MOCKS_H

#undef malloc
#undef free

#undef printf

#define malloc(X) testMalloc(X)
#define free(X) testFree(X)

#define printf(...) testPrintf(__VA_ARGS__)

#endif