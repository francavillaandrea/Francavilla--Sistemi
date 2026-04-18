#include "test_assert.h"

/**
 * passTest prints that a specified test has been passed successfully.
 *
 * @param test_name The test name to print
 */
void passTest(const char *test_name) {
  applyIndent();
  printf("✔ PASSED - %s\n", test_name);
}

/**
 * failTest prints that a specified test has failed.
 *
 * @param test_name The test name to print
 */
void failTest(const char *test_name) {
  applyIndent();
  printf("❌ FAILED - %s\n", test_name);
}

/**
 * assert prints the result of a test, based on the provided expression.
 *
 * @param test_name The test name to print
 * @param expression The expression to verify to decide if the test has passed
 */
void assert(const char *test_name, bool expression) {
  if (expression) {
    passTest(test_name);
  } else {
    failTest(test_name);
  }
}

/**
 * require prints the result of a test, based on the provided expression.
 * Additionally, it exits the program if the test fails.
 *
 * @param test_name The test name to print
 * @param expression The expression to verify to decide if the test has passed
 */
void require(const char *test_name, bool expression) {
  if (expression) {
    passTest(test_name);
  } else {
    failTest(test_name);
    exit(-1);
  }
}