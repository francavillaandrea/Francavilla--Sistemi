#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <string.h>

#include "testing.h"

#include "store.h"

#define MAX_LENGTH 100

void testCreateCar();
void testCloneCar();
void testDestroyCar();
void testSerializeCar();
void testDeserializeCar();

void testCreateStore();
void testCloneStore();
void testDestroyStore();
void testSerializeStore();
void testDeserializeStore();

int main(void) {
  testCreateCar();
  testCloneCar();
  testDestroyCar();
  testSerializeCar();
  testDeserializeCar();

  testCreateStore();
  testCloneStore();
  testDestroyStore();
  testSerializeStore();
  testDeserializeStore();

  return 0;
}

void testCreateCar() {
  openTestGroup("createCar(...)");

  typedef struct {
    char *test_name;
    char *name_param;
    float price_param;
  } createCarErrorCase;

  const createCarErrorCase test_cases[] = {
      (createCarErrorCase){"createCar(NULL, -1)", NULL, -1},
      (createCarErrorCase){"createCar(\"Testing\", -1)", "Testing", -1},
      (createCarErrorCase){"createCar(\"\", 0)", "", 0},
      (createCarErrorCase){"createCar(\"Testing\", 0)", "Testing", 0},
  };

  for (int i = 0; i < 4; i++) {
    const createCarErrorCase test_case = test_cases[i];
    Car *result = createCar(test_case.name_param, test_case.price_param);

    require(test_cases[i].test_name, result == NULL);
  }

  Car *result = createCar("Testing", 10);

  require("createCar(\"Testing\", 10)", result != NULL);
  require("createCar(\"Testing\", 10) - allocation", isAllocated(result));
  require("createCar(\"Testing\", 10) - name",
          strcmp(result->name, "Testing") == 0);
  require("createCar(\"Testing\", 10) - name (allocation)",
          isAllocated(result->name));
  require("createCar(\"Testing\", 10) - price", result->price == 10);

  free(result->name);
  free(result);

  closeTestGroup();
}

void testCloneCar() {
  openTestGroup("cloneCar(...)");

  Car *clone = cloneCar(NULL);
  require("cloneCar(NULL)", clone == NULL);

  Car car = {"Testing", 10};
  clone = cloneCar(&car);
  require("cloneCar(car)", clone != NULL);
  require("cloneCar(car) - allocation", isAllocated(clone));
  require("cloneCar(car) - name", strcmp(clone->name, car.name) == 0);
  require("cloneCar(car) - name (allocation)", isAllocated(clone->name));
  require("cloneCar(car) - price", clone->price == car.price);

  free(clone->name);
  free(clone);

  closeTestGroup();
}

void testDestroyCar() {
  openTestGroup("destroyCar(...)");

  int result = destroyCar(NULL);
  require("destroyCar(NULL)", result == -1);

  Car *car = (Car *)malloc(sizeof(Car));
  char *car_name = (char *)malloc(sizeof(char) * strlen("Testing") + 1);
  strcpy(car_name, "Testing");

  car->name = car_name;
  car->price = 10;

  result = destroyCar(car);
  require("destroyCar(car)", result == 0);
  require("destroyCar(car) - de-allocation",
          !isAllocated(car) && !isAllocated(car_name));

  closeTestGroup();
}

void testSerializeCar() {
  openTestGroup("serializeCar(...)");

  Car car = {"Testing", 10};

  FILE *fp = fopen("test-execution-serialize.txt", "w");
  require("(before)Test file must be opened for tests to work", fp != NULL);

  int result = serializeCar(NULL, NULL);
  require("serializeCar(NULL, NULL)", result == -1);

  result = serializeCar(&car, NULL);
  require("serializeCar(car, NULL)", result == -1);

  result = serializeCar(NULL, fp);
  require("serializeCar(NULL, fp)", result == -1);

  result = serializeCar(&car, fp);
  require("serializeCar(car, fp)", result == 0);

  fclose(fp);

  // Testing file contents for a correct serialization
  fp = fopen("test-execution-serialize.txt", "r");
  char file_row[MAX_LENGTH];
  fgets(file_row, MAX_LENGTH, fp);
  require("serializeCar(car, fp) - file contents",
          strcmp(file_row, "Testing 10"));

  closeTestGroup();
}

void testDeserializeCar() {
  openTestGroup("deserializeCar(...)");

  Car *result = deserializeCar(NULL);
  require("deserializeCar(NULL)", result == NULL);

  FILE *fp = fopen("test-files/deserializeCar-1.txt", "r");
  require("(before)test-files/deserializeCar-1.txt file check", fp != NULL);

  result = deserializeCar(fp);
  require("deserializeCar(fp) - Test file 1", result == NULL);

  fclose(fp);

  fp = fopen("test-files/deserializeCar-2.txt", "r");
  require("(before)test-files/deserializeCar-2.txt file check", fp != NULL);

  result = deserializeCar(fp);
  require("deserializeCar(fp) - Test file 2", result == NULL);

  fclose(fp);

  fp = fopen("test-files/deserializeCar-3.txt", "r");
  require("(before)test-files/deserializeCar-3.txt file check", fp != NULL);

  result = deserializeCar(fp);
  require("deserializeCar(fp) - Test file 3", result != NULL);
  require("deserializeCar(fp) - Test file 3 - allocation", isAllocated(result));
  require("deserializeCar(fp) - Test file 3 - name",
          strcmp(result->name, "Lotus") == 0);
  require("deserializeCar(fp) - Test file 3 - name - allocation",
          isAllocated(result->name));
  require("deserializeCar(fp) - Test file 3 - price", result->price == 70000);

  fclose(fp);

  closeTestGroup();
}

void testCreateStore() {
  openTestGroup("createStore(...)");

  typedef struct {
    char *test_name;
    char *store_name_param;
    char *manager_name_param;
    Car *cars_param;
    int cars_count_param;
  } createStoreErrorCase;

  Car cars[] = {(Car){"Testing", 10}};

  createStoreErrorCase test_cases[] = {
      (createStoreErrorCase){"createStore(NULL, NULL, NULL, -1)", NULL, NULL,
                             NULL, -1},
      (createStoreErrorCase){"createStore(\"\", NULL, NULL, -1)", "", NULL,
                             NULL, -1},
      (createStoreErrorCase){"createStore(\"Testing\", NULL, NULL, -1)",
                             "Testing", NULL, NULL, -1},
      (createStoreErrorCase){
          "createStore(\"Testing\", \"Tester Manager\", NULL, -1)", "Testing",
          "Tester Manager", NULL, -1},
      (createStoreErrorCase){"createStore(NULL, NULL, cars, -1)", NULL, NULL,
                             cars, -1},
      (createStoreErrorCase){"createStore(NULL, NULL, cars, 0)", NULL, NULL,
                             cars, 0},
      (createStoreErrorCase){"createStore(NULL, NULL, cars, 1)", NULL, NULL,
                             cars, 1},
      (createStoreErrorCase){"createStore(\"\", NULL, cars, -1)", "", NULL,
                             cars, 1},
      (createStoreErrorCase){"createStore(NULL, \"\", cars, -1)", NULL, "",
                             cars, 1},
  };

  for (int i = 0; i < 9; i++) {
    createStoreErrorCase test_case = test_cases[i];
    Store *result =
        createStore(test_case.store_name_param, test_case.manager_name_param,
                    test_case.cars_param, test_case.cars_count_param);
    require(test_case.test_name, result == NULL);
  }

  Store *store = createStore("Testing Store", "Testing Manager", cars, 1);
  require("createStore(\"Testing Store\", \"Testing Manager\", cars, 1)",
          store != NULL);
  require("createStore(\"Testing Store\", \"Testing Manager\", cars, 1) - "
          "allocation",
          isAllocated(store));
  require("createStore(\"Testing Store\", \"Testing Manager\", cars, 1) - name",
          strcmp(store->name, "Testing Store") == 0);
  require("createStore(\"Testing Store\", \"Testing Manager\", cars, 1) - name "
          "- allocation",
          isAllocated(store->name));
  require("createStore(\"Testing Store\", \"Testing Manager\", cars, 1) - "
          "manager name",
          strcmp(store->manager_name, "Testing Manager") == 0);
  require("createStore(\"Testing Store\", \"Testing Manager\", cars, 1) - "
          "manager name - allocation",
          isAllocated(store->manager_name));
  require("createStore(\"Testing Store\", \"Testing Manager\", cars, 1) - "
          "cars_count",
          store->cars_count == 1);
  require("createStore(\"Testing Store\", \"Testing Manager\", cars, 1) - "
          "cars[0] check",
          strcmp(store->cars[0].name, "Testing") == 0 &&
              store->cars[0].price == 10);

  free(store->cars[0].name);
  free(store->manager_name);
  free(store->name);
  free(store);

  closeTestGroup();
}

void testCloneStore() {
  openTestGroup("cloneStore(...)");

  Store *result = cloneStore(NULL);
  require("cloneStore(NULL)", result == NULL);

  Car cars[] = {(Car){"Testing", 10}};
  Store clone = {"Testing Store", "Testing Manager", cars, 1};

  result = cloneStore(&clone);
  require("cloneStore(store)", result != NULL);
  require("cloneStore(store) - allocation", isAllocated(result));
  require("cloneStore(store) - name - allocation", isAllocated(result->name));
  require("cloneStore(store) - cars - allocation", isAllocated(result->cars));
  require("cloneStore(store) - name check",
          strcmp(result->name, "Testing Store") == 0);
  require("cloneStore(store) - cars_count check", result->cars_count == 1);
  require("cloneStore(store) - cars[0] check",
          strcmp(result->cars[0].name, "Testing") == 0 &&
              result->cars[0].price == 10);

  closeTestGroup();
}

void testDestroyStore() {
  openTestGroup("destroyStore(...)");

  int result = destroyStore(NULL);
  require("destroyStore(NULL)", result == -1);

  char *car_name = malloc(sizeof(char) * strlen("Testing") + 1);
  car_name = strdup("Testing");
  Car *cars = (Car *)malloc(sizeof(Car));
  *cars = (Car){car_name, 10};

  char *store_name = strdup("Testing Store");
  char *manager_name = strdup("Testing Manager");
  Store *store = (Store *)malloc(sizeof(Store));
  *store = (Store){store_name, manager_name, cars, 1};

  result = destroyStore(store);
  require("destroyStore(store)", result == 0);
  require("destroyStore(store) - de-allocation",
          !isAllocated(store) && !isAllocated(store_name) &&
              !isAllocated(manager_name) && !isAllocated(cars) &&
              !isAllocated(car_name));

  closeTestGroup();
}

void testSerializeStore() {
  openTestGroup("serializeStore(...)");

  FILE *fp = fopen("test-execution-serialize.txt", "w");
  require("(before)Test file must be opened for tests to work", fp != NULL);

  Car cars[] = {(Car){"Testing", 1000}};
  Store store = {"TestingStore", "TestingManager", cars, 1};

  int result = serializeStore(NULL, NULL);
  require("serializeStore(NULL, NULL)", result == -1);

  result = serializeStore(&store, NULL);
  require("serializeStore(store, NULL)", result == -1);

  result = serializeStore(NULL, fp);
  require("serializeStore(NULL, fp)", result == -1);

  result = serializeStore(&store, fp);
  require("serializeStore(store, fp)", result == 0);

  fclose(fp);

  // Testing file contents for a correct serialization
  fp = fopen("test-execution-serialize.txt", "r");
  char file_row[MAX_LENGTH];
  fgets(file_row, MAX_LENGTH, fp);
  bool test_passed = strcmp(file_row, "TestingStore TestingManager 1\n") == 0;

  fgets(file_row, MAX_LENGTH, fp);
  test_passed = test_passed || strcmp(file_row, "Testing 1000\n") == 0;

  require("serializeStore(store, fp) - file contents", test_passed);

  closeTestGroup();
}

void testDeserializeStore() {
  openTestGroup("deserializeStore(...)");

  Store *result = deserializeStore(NULL);
  require("deserializeStore(NULL)", result == NULL);

  FILE *fp = fopen("test-files/deserializeStore-1.txt", "r");
  require("(before)test-files/deserializeStore-1.txt file check", fp != NULL);

  result = deserializeStore(fp);
  require("deserializeStore(fp) - Test file 1", result == NULL);

  fclose(fp);

  fp = fopen("test-files/deserializeStore-2.txt", "r");
  require("(before)test-files/deserializeStore-2.txt file check", fp != NULL);

  result = deserializeStore(fp);
  require("deserializeStore(fp) - Test file 2", result == NULL);

  fclose(fp);

  fp = fopen("test-files/deserializeStore-3.txt", "r");
  require("(before)test-files/deserializeStore-3.txt file check", fp != NULL);

  result = deserializeStore(fp);
  require("deserializeStore(fp) - Test file 3", result == NULL);

  fclose(fp);

  fp = fopen("test-files/deserializeStore-4.txt", "r");
  require("(before)test-files/deserializeStore-4.txt file check", fp != NULL);

  Car cars[] = {
      (Car){"Ferrari", 1000000},  (Car){"Lamborghini", 2000000},
      (Car){"Maserati", 500000},  (Car){"Pagani", 3000000},
      (Car){"AlfaRomeo", 100000},
  };
  Store expected_result = {"GoldenStateDealers", "ElonMusk", cars, 5};
  result = deserializeStore(fp);
  require("deserializeStore(fp) - Test file 4", result != NULL);
  require("deserializeStore(fp) - Test file 4 - allocation",
          isAllocated(result));
  require("deserializeStore(fp) - Test file 4 - name - allocation",
          isAllocated(result->name));
  require("deserializeStore(fp) - Test file 4 - manager name - allocation",
          isAllocated(result->manager_name));

  bool test_passed =
      strcmp(result->name, expected_result.name) == 0 &&
      strcmp(result->manager_name, expected_result.manager_name) == 0;
  for (int i = 0; test_passed && i < 5; i++) {
    bool car_check_passed =
        strcmp(result->cars[i].name, expected_result.cars[i].name) == 0 &&
        result->cars[i].price == expected_result.cars[i].price;
    test_passed = test_passed && car_check_passed;
  }

  require("deserializeStore(fp) - Test file 4 - contents", test_passed);

  fclose(fp);

  closeTestGroup();
}
