#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

// Iterative Factorial
unsigned long long factorialIterative(int n)
{
    unsigned long long fact = 1;

    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

// Recursive Factorial
unsigned long long factorialRecursive(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

// Display Result
void displayResult(const string& method,
                   unsigned long long result,
                   double time)
{
    cout << "\n" << method << "\n";
    cout << "--------------------------------\n";
    cout << "Factorial Result : " << result << endl;
    cout << "Execution Time   : "
         << fixed << setprecision(3)
         << time << " nanoseconds\n";
}

int main()
{
    int n;

    cout << "========================================\n";
    cout << "       FACTORIAL PERFORMANCE TEST       \n";
    cout << "========================================\n";

    cout << "Enter a number (0 - 20): ";
    cin >> n;

    // Input validation
    if (cin.fail() || n < 0 || n > 20)
    {
        cout << "\nInvalid input!\n";
        cout << "Please enter a number between 0 and 20.\n";
        return 1;
    }

    // ---------------- Iterative Method ----------------
    auto startIterative = high_resolution_clock::now();

    unsigned long long iterativeResult =
        factorialIterative(n);

    auto endIterative = high_resolution_clock::now();

    duration<double, nano> iterativeTime =
        endIterative - startIterative;

    // ---------------- Recursive Method ----------------
    auto startRecursive = high_resolution_clock::now();

    unsigned long long recursiveResult =
        factorialRecursive(n);

    auto endRecursive = high_resolution_clock::now();

    duration<double, nano> recursiveTime =
        endRecursive - startRecursive;

    // ---------------- Results ----------------
    cout << "\n========================================\n";
    cout << "              RESULTS                   \n";
    cout << "========================================\n";

    displayResult("ITERATIVE METHOD",
                  iterativeResult,
                  iterativeTime.count());

    displayResult("RECURSIVE METHOD",
                  recursiveResult,
                  recursiveTime.count());

    // ---------------- Comparison ----------------
    cout << "\n========================================\n";
    cout << "             COMPARISON                 \n";
    cout << "========================================\n";

    cout << "Iterative Complexity : O(n)\n";
    cout << "Iterative Space      : O(1)\n\n";

    cout << "Recursive Complexity : O(n)\n";
    cout << "Recursive Space      : O(n)\n";

    cout << "\nBoth methods produce the same result: ";

    if (iterativeResult == recursiveResult)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
