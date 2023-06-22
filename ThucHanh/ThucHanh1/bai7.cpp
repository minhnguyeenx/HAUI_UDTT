#include <iostream>

using namespace std;

int n = 9;

int *fib = new int[n + 1];

double fibonacci(int n)
{
    if (fib[n] != 0)
        return fib[n];
    if (n <= 2)
        return 1;
    fib[n - 1] = fibonacci(n - 1);
    fib[n - 2] = fibonacci(n - 2);
    return fib[n - 1] + fib[n - 2];
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i <= n; i++)
    {
        fib[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": " << fibonacci(i) << "\n";
    }
    return 0;
}
