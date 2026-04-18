#include "test_output.h"

#undef printf

static char captured_messages[MAX_CAPTURED_MESSAGES][MAX_BUFFER_LENGTH];
static unsigned int last_message_index = 0;

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
int testPrintf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  int written_chars = vsnprintf(captured_messages[last_message_index],
                                MAX_BUFFER_LENGTH, format, args);
  va_end(args);
  
  printf("%s", captured_messages[last_message_index]);

  last_message_index++;

  return written_chars;
}

/**
 * Retrieve the last captured messages printed using testPrintf function.
 *
 * @param n The number of last messages to retrieve
 * @returns A pointer to an array of strings containing the last captured
 * messages, or NULL if n is greater than the total number of captured messages
 */
char **getLastCapturedPrints(int n) {
  if (n > last_message_index) {
    // printf("Cannot get last captured print: no prints in the buffer\n");
    return NULL;
  }

  if (n <= 0 || n > last_message_index) {
    return NULL;
  }

  char **last_messages = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    last_messages[n - i - 1] = captured_messages[last_message_index - i - 1];
  }

  last_message_index -= n;

  return last_messages;
}
