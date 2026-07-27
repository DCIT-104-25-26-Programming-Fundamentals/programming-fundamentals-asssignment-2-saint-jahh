// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void transposeMatrix(int matrix[10][10], int rows, int cols, int transpose[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int first[10][10], int second[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void multiplyMatrices(int first[10][10], int second[10][10], int result[10][10], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    int matrix[10][10];
    int transpose[10][10];
    int secondMatrix[10][10];
    int sum[10][10];
    int product[10][10];

    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nEnter matrix values:" << endl;
    readMatrix(matrix, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    transposeMatrix(matrix, rows, cols, transpose);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transpose, cols, rows);

    cout << "\nEnter second matrix values:" << endl;
    readMatrix(secondMatrix, rows, cols);

    addMatrices(matrix, secondMatrix, sum, rows, cols);
    cout << "\nSum of Matrices:" << endl;
    printMatrix(sum, rows, cols);

    int rowsB, colsB;
    cout << "\nEnter number of rows for second matrix for multiplication: ";
    cin >> rowsB;
    cout << "Enter number of columns for second matrix for multiplication: ";
    cin >> colsB;

    int matrixB[10][10];
    cout << "\nEnter values for multiplication matrix:" << endl;
    readMatrix(matrixB, rowsB, colsB);

    if (cols != rowsB) {
        cout << "\nMatrix multiplication is not possible with these dimensions." << endl;
    } else {
        multiplyMatrices(matrix, matrixB, product, rows, cols, colsB);
        cout << "\nProduct of Matrices:" << endl;
        printMatrix(product, rows, colsB);
    }

    return 0;
}

