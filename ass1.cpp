#include <iostream>
using namespace std;

// Function to compute nth Fibonacci number using recursion

int fibonacciRecursive(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main()
{
    int n;
    cout << "Enter The term number (n)";
    cin >> n;

    int result = fibonacciRecursive(n);
    cout << "Fibonacci number at position" << n << "is:" << result << endl;
    return 0;
}

#include <iostream>
using namespace std;

// Iterative function to calculate nth Fibonacci number
int fibonacciIterative(int n)
{
    if (n <= 1)
        return n;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n;
    cout << "Enter the term number (n): ";
    cin >> n;

    int result = fibonacciIterative(n);

    cout << "Fibonacci number at position " << n << " is: " << result << endl;

    return 0;
}