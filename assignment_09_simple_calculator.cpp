// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }
double modulus(double a, double b) { return fmod(a, b); }
double exponentiate(double a, double b) { return pow(a, b); }

int main() {
    while (true) {
        cout << "\n============================" << endl;
        cout << "      SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";

        int choice;
        cin >> choice;

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        double firstNumber, secondNumber;
        cout << "Enter first number: ";
        cin >> firstNumber;
        cout << "Enter second number: ";
        cin >> secondNumber;

        if (choice == 1) {
            cout << "Result: " << fixed << setprecision(2) << add(firstNumber, secondNumber) << endl;
        } else if (choice == 2) {
            cout << "Result: " << fixed << setprecision(2) << subtract(firstNumber, secondNumber) << endl;
        } else if (choice == 3) {
            cout << "Result: " << fixed << setprecision(2) << multiply(firstNumber, secondNumber) << endl;
        } else if (choice == 4) {
            if (secondNumber == 0) {
                cout << "Error: Cannot divide by zero." << endl;
            } else {
                cout << "Result: " << fixed << setprecision(2) << divide(firstNumber, secondNumber) << endl;
            }
        } else if (choice == 5) {
            if (secondNumber == 0) {
                cout << "Error: Cannot divide by zero." << endl;
            } else {
                cout << "Result: " << fixed << setprecision(2) << modulus(firstNumber, secondNumber) << endl;
            }
        } else if (choice == 6) {
            cout << "Result: " << fixed << setprecision(2) << exponentiate(firstNumber, secondNumber) << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

