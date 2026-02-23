#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_CELL_LENGTH 100

/**
 * Represents a 2D Matrix of integers
 */
typedef struct
{
    int cells[MAX_COLUMNS][MAX_ROWS];
    int rows;
    int columns;
} IntMatrix2D;

// Prototypes
int initializeIntMatrix2D(IntMatrix2D*, int, int, int);
int cloneIntMatrix2D(IntMatrix2D*, IntMatrix2D*);
bool isValidIntMatrix2D(IntMatrix2D*);
int sumIntMatrix2D(IntMatrix2D*, IntMatrix2D*);
int elementsSumIntMatrix2D(IntMatrix2D*);
int diagonalSumIntMatrix2D(IntMatrix2D*);

/**
 * Initializes a 2D integer matrix with a default value.
 * 
 * @param matrix Pointer to the matrix to initialize, must not be NULL.
 * @param defaultValue The value to fill the matrix with, must be >= 0.
 * @param columns Number of columns in the matrix, must be > 0 and < MAX_COLUMNS.
 * @param rows Number of rows in the matrix, must be > 0 and < MAX_ROWS.
 * @return 0 if successful, -1 if an error occurs.
 */
int initializeIntMatrix2D(IntMatrix2D *matrix, int defaultValue, int columns, int rows)
{
    if (
        matrix == NULL ||
        defaultValue < 0 ||
        columns <= 0 || columns >= MAX_COLUMNS ||
        rows <= 0 || rows >= MAX_ROWS
    )
    {
        return -1;
    }
    
    // manca assegnamento di matrix->rows e matrix->columns (-0.5)
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix->cells[i][j] = defaultValue;
        }
    }
    return 0;
}

/**
 * Clones a 2D integer matrix from src into dest.
 * 
 * @param dest Pointer to the destination matrix, must not be NULL.
 * @param src Pointer to the source matrix to clone, must not be NULL.
 * @return 0 if successful, -1 if an error occurs.
 */
int cloneIntMatrix2D(IntMatrix2D *dest, IntMatrix2D *src)
{
    // occorre controllare se src è valido (-0.5)
    if (
        dest == NULL ||
        src == NULL
    )
    {
        return -1;
    }
    
    for (int i = 0; i < src->rows; i++)
    {
        for (int j = 0; j < src->columns; j++)
        {
            dest->cells[i][j] = src->cells[i][j];
        }
    }
    dest->rows = src->rows;
    dest->columns = src->columns;
    return 0;
}

/**
 * Checks if a 2D integer matrix is valid.
 * 
 * @param matrix Pointer to the matrix to validate, must not be NULL.
 * @return true if the matrix is valid, false otherwise.
 */
bool isValidIntMatrix2D(IntMatrix2D *matrix)
{
    if (
        matrix != NULL &&
        matrix->rows >= 0 &&
        matrix->rows <= MAX_ROWS &&
        matrix->columns >= 0 &&
        matrix->columns <= MAX_COLUMNS
    )
    {
        return true;
    }
    return false;
}

/**
 * Sums two 2D integer matrices.
 * 
 * The 2 matrices must have the same dimensions. The result is stored in matrixA.
 * 
 * @param matrixA Pointer to the first matrix (result will be stored here).
 * @param matrixB Pointer to the second matrix to add.
 * @return 0 if successful, -1 if an error occurs.
 */
int sumIntMatrix2D(IntMatrix2D *matrixA, IntMatrix2D *matrixB)
{
    if (
        matrixA == NULL ||
        matrixB == NULL ||
        matrixA->columns != matrixB->columns ||
        matrixA->rows != matrixB->rows
    )
    {
        return -1;
    }

    for (int i = 0; i < matrixA->rows; i++)
    {
        for (int j = 0; j < matrixA->columns; j++)
        {
            matrixA->cells[i][j] += matrixB->cells[i][j];
        }
    }
    return 0;
}

/**
 * Calculates the sum of all elements in a 2D integer matrix.
 * 
 * @param matrix Pointer to the matrix, must not be NULL.
 * @return The sum of all elements in the matrix, or -1 if an error occurs.
 */
int elementsSumIntMatrix2D(IntMatrix2D *matrix)
{
    // manca controllo di validità della matrice (-0.5)
    if (matrix == NULL)
    {
        return -1;
    }
    
    int sum = 0;
    
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            sum += matrix->cells[i][j];
        }
    }
    
    return sum;
}

/**
 * Calculates the sum of the diagonal elements of a square 2D integer matrix.
 * 
 * The matrix must be square.
 * 
 * @param matrix Pointer to the matrix.
 * @return The sum of the diagonal elements, or -1 if the matrix is not square.
 */
int diagonalSumIntMatrix2D(IntMatrix2D *matrix)
{
    if (
        matrix == NULL ||
        matrix->columns != matrix->rows
    )
    {
        return -1;
    }
    
    int sum;

    for (int i = 0; i < matrix->rows; i++)
    {
        sum += matrix->cells[i][i];
    }

    // manca la seconda diagonale (-0.5)
    
    return sum;
}

#endif