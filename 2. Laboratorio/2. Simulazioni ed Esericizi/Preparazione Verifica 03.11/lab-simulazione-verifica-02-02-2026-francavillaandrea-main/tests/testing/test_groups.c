#include "test_groups.h"

static bool group_open = false;

/**
 * applyIndent applies the indentation in case of test groups
 */
void applyIndent() {
  if (group_open) {
    printf("  ");
  }
}

/**
 * openTestGroup opens a new test group and allows to apply indent to better
 * organize tests.
 *
 * @param test_group_name The name of the test group
 */
void openTestGroup(const char *test_group_name) {
  if (group_open) {
    closeTestGroup();
  }
  group_open = true;

  printf("%s\n", test_group_name);
}

/**
 * closeTestGroup closes a previously open test group.
 */
void closeTestGroup() {
  if (group_open) {
    group_open = false;

    printf("\n");
  }
}