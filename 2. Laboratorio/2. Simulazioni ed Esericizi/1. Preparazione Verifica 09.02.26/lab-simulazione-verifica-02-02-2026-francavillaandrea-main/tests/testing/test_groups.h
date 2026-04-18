#ifndef TEST_GROUPS_H
#define TEST_GROUPS_H

#include <stdbool.h>
#include <stdio.h>

/**
 * applyIndent applies the indentation in case of test groups
 */
void applyIndent();

/**
 * openTestGroup opens a new test group and allows to apply indent to better
 * organize tests.
 *
 * @param test_group_name The name of the test group
 */
void openTestGroup(const char *);

/**
 * closeTestGroup closes a previously open test group.
 */
void closeTestGroup();

#endif
