#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "testing/test.h"

#include "../node.h"
#include "../set.h"

#define MAX_LENGTH 100
#define TEST_INSERT_SIZE 5

void testCreateNode();
void testCloneNode();
void testDestroyNode();
void testCreateEmptySet();
void testCloneSet();
void testDestroySet();
void testGetSetSize();
void testSetContains();
void testInsertNodeInSet();
void testPrintSet();

int main(void) {
  testCreateNode();
  testCloneNode();
  testDestroyNode();

  testCreateEmptySet();
  testCloneSet();
  testDestroySet();

  testGetSetSize();
  testSetContains();

  testInsertNodeInSet();

  testPrintSet();

  return 0;
}

void testCreateNode() {
  openTestGroup("createNode(...)");

  for (int i = 0; i < 5; i++) {
    char buffer[MAX_LENGTH];
    sprintf(buffer, "%d", i);
    Node *result = createNode(buffer);

    char test_name[MAX_LENGTH];
    sprintf(test_name, "createNode(\"%d\")", i);
    assert(test_name, result != NULL && strcmp(result->value, buffer) == 0);

    free(result);
  }

  closeTestGroup();
}

void testCloneNode() {
  openTestGroup("cloneNode(...)");

  Node *result = cloneNode(NULL);
  assert("cloneNode(NULL)", result == NULL);

  for (int i = 0; i < 5; i++) {
    char buffer[MAX_LENGTH];
    sprintf(buffer, "%d", i);
    Node temp = (Node){buffer, NULL};
    result = cloneNode(&temp);

    char test_name[MAX_LENGTH];
    sprintf(test_name, "cloneNode(temp) - Test %d", i);
    assert(test_name, result != NULL &&
                          strcmp(result->value, temp.value) == 0 &&
                          result->next == NULL);

    free(result);
  }

  closeTestGroup();
}

void testDestroyNode() {
  openTestGroup("destroyNode(...)");

  int result = destroyNode(NULL);
  assert("destroyNode(NULL)", result == -1);

  Node *node = malloc(sizeof(Node));
  node->value = (char *)malloc(sizeof(char) * 2);
  strcpy(node->value, "5");
  node->next = NULL;

  result = destroyNode(node);
  assert("destroyNode(node)", result == 0);
  assert("destroyNode(node) - de-allocation", !isAllocated(node));

  closeTestGroup();
}

void testCreateEmptySet() {
  openTestGroup("createEmptySet(...)");

  Set *result = createEmptySet();
  assert("createEmptySet()", result != NULL && result->first == NULL);

  closeTestGroup();
}

void testCloneSet() {
  openTestGroup("cloneSet(...)");

  Set *result = cloneSet(NULL);
  assert("cloneSet(NULL)", result == NULL);

  Set temp_list = (Set){NULL};
  result = cloneSet(&temp_list);
  assert("cloneSet(empty_list)", result != NULL && result->first == NULL);

  for (int i = 0; i < 5; i++) {
    char test_name[MAX_LENGTH];
    sprintf(test_name, "cloneSet(list) - Test %d", i);

    char buffer[MAX_LENGTH];
    sprintf(buffer, "%d", i);
    Node temp_node = (Node){buffer, NULL};
    temp_list = (Set){&temp_node};
    result = cloneSet(&temp_list);
    assert(test_name, result != NULL && result->first != NULL &&
                          strcmp(result->first->value, temp_node.value) == 0 &&
                          result->first->next == temp_node.next);
  }

  closeTestGroup();
}

void testDestroySet() {
  openTestGroup("destroySet(...)");

  int result = destroySet(NULL);
  assert("destroySet(NULL)", result == -1);

  Set *temp_list = (Set *)malloc(sizeof(Set));
  *temp_list = (Set){NULL};
  result = destroySet(temp_list);
  assert("destroySet(empty_list)", result == 0 && !isAllocated(temp_list));

  for (int i = 0; i < 5; i++) {
    char test_name[MAX_LENGTH];
    sprintf(test_name, "destroySet(list) - Test %d", i);

    Node *temp_node = (Node *)malloc(sizeof(Node));
    char *node_value = (char *)malloc(sizeof(char) * 5);
    strcpy(node_value, "test");
    *temp_node = (Node){node_value, NULL};

    temp_list = (Set *)malloc(sizeof(Set));
    *temp_list = (Set){temp_node};
    result = destroySet(temp_list);
    assert(test_name,
           result == 0 && !isAllocated(temp_list) && !isAllocated(temp_node));
  }

  closeTestGroup();
}

void testGetSetSize() {
  openTestGroup("getSetSize(...)");

  int result = getSetSize(NULL);
  assert("getSetSize(NULL)", result == -1);

  Set temp_list = (Set){NULL};
  result = getSetSize(&temp_list);
  assert("getSetSize(empty_list)", result == 0);

  Node temp_node_3 = (Node){"3", NULL};
  Node temp_node_2 = (Node){"2", &temp_node_3};
  Node temp_node_1 = (Node){"1", &temp_node_2};

  temp_list = (Set){&temp_node_1};
  result = getSetSize(&temp_list);
  assert("getSetSize(list) - Test 1", result == 3);

  temp_node_2.next = NULL;
  result = getSetSize(&temp_list);
  assert("getSetSize(list) - Test 2", result == 2);

  temp_node_1.next = NULL;
  result = getSetSize(&temp_list);
  assert("getSetSize(list) - Test 3", result == 1);

  closeTestGroup();
}

void testSetContains() {
  openTestGroup("setContains(...)");

  bool result = setContains(NULL, "1");
  assert("setContains(NULL, \"1\")", result == false);

  Set temp_list = (Set){NULL};
  result = setContains(&temp_list, "1");
  assert("setContains(empty_list, \"1\")", result == false);

  Node temp_node_3 = (Node){"3", NULL};
  Node temp_node_2 = (Node){"2", &temp_node_3};
  Node temp_node_1 = (Node){"1", &temp_node_2};

  temp_list = (Set){&temp_node_1};
  result = setContains(&temp_list, "4");
  assert("setContains(list, \"4\") - Test 1", result == false);

  result = setContains(&temp_list, "2");
  assert("setContains(list, \"2\") - Test 1", result == true);

  result = setContains(&temp_list, "1");
  assert("setContains(list, \"1\") - Test 1", result == true);

  result = setContains(&temp_list, "3");
  assert("setContains(list, \"3\") - Test 1", result == true);

  temp_node_2.next = NULL;

  result = setContains(&temp_list, "4");
  assert("setContains(list, \"4\") - Test 2", result == false);

  result = setContains(&temp_list, "2");
  assert("setContains(list, \"2\") - Test 2", result == true);

  result = setContains(&temp_list, "1");
  assert("setContains(list, \"1\") - Test 2", result == true);

  result = setContains(&temp_list, "3");
  assert("setContains(list, \"3\") - Test 2", result == false);

  temp_node_1.next = NULL;

  result = setContains(&temp_list, "4");
  assert("setContains(list, \"4\") - Test 3", result == false);

  result = setContains(&temp_list, "2");
  assert("setContains(list, \"2\") - Test 3", result == false);

  result = setContains(&temp_list, "1");
  assert("setContains(list, \"1\") - Test 3", result == true);

  result = setContains(&temp_list, "3");
  assert("setContains(list, \"3\") - Test 3", result == false);

  closeTestGroup();
}

static int testInsert(int expected[TEST_INSERT_SIZE],
                      int actual[TEST_INSERT_SIZE]) {
  Set temp_list = (Set){NULL};
  for (int i = 0; i < TEST_INSERT_SIZE; i++) {
    char buffer[MAX_LENGTH];
    sprintf(buffer, "%d", actual[i]);
    int result = insertNodeInSet(&temp_list, buffer, i);
    if (result == -1) {
      return -1;
    }
  }

  int i = 0;
  Node *iterator = temp_list.first;
  while (iterator != NULL && i < TEST_INSERT_SIZE) {
    char expected_buffer[MAX_LENGTH];
    sprintf(expected_buffer, "%d", expected[i]);
    if (strcmp(iterator->value, expected_buffer) != 0) {
      return -1;
    }

    iterator = iterator->next;
    i++;
  }

  if (i != TEST_INSERT_SIZE) {
    return -1;
  }

  return 0;
}

void testInsertNodeInSet() {
  openTestGroup("insertNode(...)");

  int result = insertNodeInSet(NULL, "1", 0);
  assert("insertNodeInSet(NULL, \"1\", 0)", result == -1);

  int expected[TEST_INSERT_SIZE] = {1, 2, 3, 4, 5};
  // sorted insertion test
  int test_insert_values[TEST_INSERT_SIZE] = {1, 2, 3, 4, 5};
  result = testInsert(expected, test_insert_values);
  assert("insertNodeInSet - test already sorted", result == 0);

  // reverse insertion test
  test_insert_values[0] = 5;
  test_insert_values[1] = 4;
  test_insert_values[2] = 3;
  test_insert_values[3] = 2;
  test_insert_values[4] = 1;

  result = testInsert(expected, test_insert_values);
  assert("insertNodeInSet - test reverse sorted", result == 0);

  // // unsorted insertion tests
  test_insert_values[0] = 3;
  test_insert_values[1] = 1;
  test_insert_values[2] = 5;
  test_insert_values[3] = 4;
  test_insert_values[4] = 2;

  result = testInsert(expected, test_insert_values);
  assert("insertNodeInSet - test randomly unsorted", result == 0);

  closeTestGroup();
}

void testPrintSet() {
  openTestGroup("printSet(...)");

  // NULL list check
  printSet(NULL);
  char **captured_output = getLastCapturedPrints(0);
  assert("printSet(NULL)", captured_output == NULL);

  // empty list check
  Set temp_list = (Set){NULL};
  printSet(&temp_list);
  captured_output = getLastCapturedPrints(0);
  assert("printSet(empty_list)", captured_output == NULL);

  // normal list check
  Node temp_node_2 = (Node){"2", NULL};
  Node temp_node_1 = (Node){"1", &temp_node_2};
  temp_list = (Set){&temp_node_1};
  printSet(&temp_list);
  captured_output = getLastCapturedPrints(2);
  assert("printSet(list)", captured_output != NULL && 
         strcmp(captured_output[0], "1\n") == 0 &&
         strcmp(captured_output[1], "2\n") == 0);

  closeTestGroup();
}
