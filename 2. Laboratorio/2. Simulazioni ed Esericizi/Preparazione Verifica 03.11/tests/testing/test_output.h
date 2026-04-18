#ifndef TEST_OUTPUT_H
#define TEST_OUTPUT_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPTURED_MESSAGES 50
#define MAX_BUFFER_LENGTH 1000

/**
 * This function is a mock of the printf function that allows to test
 * dynamic allocation behaviors. You can later get the captured output
 * using getLastCapturedPrints function.
 *
 * @param format The format string for the output
 * @param ... The arguments to be formatted and printed
 *
 * @returns The number of characters printed
 *
 * @see getLastCapturedPrints
 */
int testPrintf(const char *format, ...);

/**
 * Retrieve the last captured messages printed using testPrintf function.
 *
 * @param n The number of last messages to retrieve
 * @returns A pointer to an array of strings containing the last captured
 * messages, or NULL if n is greater than the total number of captured messages
 */
char **getLastCapturedPrints(int n);

#endif