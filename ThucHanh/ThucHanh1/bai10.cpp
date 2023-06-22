#include <iostream>

using namespace std;

int sumOfOdds(int arr[], int n)
{
    if (n == 1)
        return arr[0] % 2 == 0 ? 0 : arr[0];

    int last = arr[n - 1] % 2 == 0 ? 0 : arr[n - 1];
    return sumOfOdds(arr, n - 1) + last;
}

int main(int argc, char const *argv[])
{
    // tinh tong cac so le
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;

    cout << sumOfOdds(arr, n);

    return 0;
}
