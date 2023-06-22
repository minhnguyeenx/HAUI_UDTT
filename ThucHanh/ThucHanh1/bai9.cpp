#include <iostream>

using namespace std;

long sumDigit(int n){
    if(n < 1) return 0;
    return sumDigit(n / 10) + n % 10;
}

int main(int argc, char const *argv[])
{
    cout << sumDigit(1123);

    return 0;
}
