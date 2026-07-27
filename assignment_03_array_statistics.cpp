// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
using namespace std;

int calculateSum(const vector<int>& numbers) {
    int total = 0;
    for (int value : numbers) {
        total += value;
    }
    return total;
}

double calculateAverage(const vector<int>& numbers) {
    if (numbers.empty()) return 0.0;
    return static_cast<double>(calculateSum(numbers)) / numbers.size();
}

int calculateMax(const vector<int>& numbers) {
    if (numbers.empty()) return 0;
    int largest = numbers[0];
    for (int i = 1; i < static_cast<int>(numbers.size()); i++) {
        if (numbers[i] > largest) largest = numbers[i];
    }
    return largest;
}

int calculateMin(const vector<int>& numbers) {
    if (numbers.empty()) return 0;
    int smallest = numbers[0];
    for (int i = 1; i < static_cast<int>(numbers.size()); i++) {
        if (numbers[i] < smallest) smallest = numbers[i];
    }
    return smallest;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    vector<int> numbers;
    for (int i = 1; i <= n; i++) {
        int value;
        cout << "Enter number " << i << ": ";
        cin >> value;
        numbers.push_back(value);
    }

    cout << endl;
    cout << "Results:" << endl;
    cout << "Sum:     " << calculateSum(numbers) << endl;
    cout << "Average: " << calculateAverage(numbers) << endl;
    cout << "Maximum: " << calculateMax(numbers) << endl;
    cout << "Minimum: " << calculateMin(numbers) << endl;

    return 0;
}

