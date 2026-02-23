#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

// Car represents a single car in a store
typedef struct
{
    // The car name
    char *name;

    // The price of the car, in €
    float price;
} Car;

/**

 * createCar creates a valid Car entity.
 *
 * @param name The name of the car, must not be empty or NULL
 * @param price The price of the car, must be > 0
 *
 * @returns The valid car, or NULL in case of any error
 */
Car *createCar(char *name, float price)
{
    // implement function logic here
    if (name == NULL || strlen(name) == 0 || price <= 0)
    {
        return NULL;
    }

    Car *car = (Car *)malloc(sizeof(Car));
    car->name = (char *)malloc(strlen(name) + 1);
    strcpy(car->name, name);
    car->price = price;

    return car;

}

/**
 * cloneCar creates a valid Car entity by copying another one.
 *
 * @param car The car to clone, must not be NULL
 *
 * @returns The cloned car, or NULL in case of any error
 */

Car *cloneCar(Car *car)
{
    if (car == NULL)
    {
        return NULL;
    }

    return createCar(car->name, car->price);
}

/**
 * destroyCar destroys a previously created Car entity and deallocates
 * it completely.
 *
 * @param car The car to destroy, must not be NULL
 *
 * @returns -1 in case of any error, 0 otherwise
 */
int destroyCar(Car *car)
{
    // implement function logic here
    if (car == NULL)
    {
        return -1;
    }

    free(car->name);
    free(car);
    return 0;
}

/**
 * serializeCar serializes the car into the specified file.
 *
 * @param car The car to serialize, must not be NULL
 * @param out_file The output file to serialize into, must not be NULL
 *
 * @returns -1 in case of any error, 0 otherwise
 */
int serializeCar(Car *car, FILE *out_file)
{
    // implement function logic here
    if (car == NULL || out_file == NULL)
    {
        return -1;
    }

    fprintf(out_file, "%s %d", car->name, car->price);
    return 0;
}

/**
 * deserializeCar deserializes the car from the specified file.
 *
 * @param in_file The output file to deserialize from, must not be NULL
 *
 * @returns The deserialized car, or NULL in case of any error
 */
Car *deserializeCar(FILE *in_file)
{
    // implement function logic here
    if (in_file == NULL)
    {
        return NULL;
    }

    char name[MAX_LENGTH];
    int price;

    if (fscanf(in_file, "%s %d", name, &price) != 2)
    {
        return NULL;
    }

    return createCar(name, price);
    return NULL;
}

// Store represents a car store.
typedef struct
{
    // The name of the store
    char *name;

    // The name of the manager of the store
    char *manager_name;

    // The array of cars of the store
    Car *cars;

    // The store cars count
    int cars_count;
} Store;

/**
 * createStore creates a valid Store entity.
 *
 * @param name The name of the store, must not be empty or NULL
 * @param manager_name The name of the store, must not be empty or NULL
 * @param cars The array of cars, must not be NULL
 * @param cars_count The number of the cars of the store, must be > 0
 *
 * @returns The valid store, or NULL in case of any error
 */
Store *createStore(char *name, char *manager_name, Car *cars, int cars_count)
{
    // implement function logic here
    if (name == NULL || strlen(name) == 0 || manager_name == NULL || cars_count <= 0 || cars == NULL)
    {
        return NULL;
    }

    Store *store = (Store *)malloc(sizeof(Store));
    store->name = (char *)malloc(strlen(name) + 1);
    store->manager_name = (char*)malloc(strlen(manager_name)+ 1 );
    strcpy(store->name, name);

    store->cars = (Car *)malloc(sizeof(Car) *  cars_count);
    for (int i = 0; i < cars_count; i++)
    {
        store->cars[i].name = (char *)malloc(strlen(cars[i].name) + 1);
        strcpy(store->cars[i].name, cars[i].name);
        store->cars[i].price = cars[i].price;
    }

    store->cars_count = cars_count;
    return store;
}

/**
 * cloneStore creates a valid Store entity by copying another one.
 *
 * @param store The store to clone, must not be NULL
 *
 * @returns The cloned store, or NULL in case of any error
 */
Store *cloneStore(Store *store)
{
    // implement function logic here
    if (store == NULL)
    {
        return NULL;
    }

    return createStore(store->name, store->manager_name, store->cars_count, store->cars);
}

/**
 * destroyStore destroys a previously created Store entity and deallocates
 * it completely.
 *
 * @param store The store to destroy, must not be NULL
 *
 * @returns -1 in case of any error, 0 otherwise
 */
int destroyStore(Store *store)
{
    // implement function logic here
    if (store == NULL)
    {
        return -1;
    }

    for (int i = 0; i < store->cars_count; i++)
    {
        free(store->cars[i].name);
    }

    free(store->cars);
    free(store->name);
    free(store);
    return 0;
}

/**
 * serializeStore serializes the store into the specified file.
 *
 * @param store The store to serialize, must not be NULL
 * @param out_file The output file to serialize into, must not be NULL
 *
 * @returns -1 in case of any error, 0 otherwise
 */
int serializeStore(Store *store, FILE *out_file)
{
    // implement function logic here
    if (store == NULL || out_file == NULL)
    {
        return -1;
    }

    fprintf(out_file, "%s %d\n", store->name, store->cars_count);

    for (int i = 0; i < store->cars_count; i++)
    {
        if (serializePlayer(&store->cars[i], out_file) == -1)
        {
            return -1;
        }
        fprintf(out_file, "\n");
    }
    return 0;
}

/**
 * deserializeStore deserializes the store from the specified file.
 *
 * @param in_file The output file to deserialize from, must not be NULL
 *
 * @returns The deserialized store, or NULL in case of any error
 */
Store *deserializeStore(FILE *in_file)
{
    // implement function logic here
    if (in_file == NULL)
    {
        return NULL;
    }

    char name[MAX_LENGTH];
    char manager_name[MAX_LENGTH];
    int cars_count;

    if (fscanf(in_file, "%s %d\n", name, &cars_count) != 2)
    {
        return NULL;
    }

    Store *cars = (Store *)malloc(sizeof(Store) *  cars_count);
    for (int i = 0; i < cars_count; i++)
    {
        Store *store = deserializePlayer(in_file);
        if (store == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(store[j].name);
            }
            free(cars);
            return NULL;
        }
        cars[i] = *store;
        free(store);
    }

    Store *store = createStore(name, manager_name, cars,cars_count;

                               for (int i = 0; i < cars_count; i++)
{
    free(cars[i].name);
    }
    free(cars);

    return Store;
}

