#include <iostream>

using namespace std;

int min_chan(int a[], int left, int right){
    int n = right - left + 1;
    if(n == 1){
        return a[left] % 2 == 0 ? left : -1;
    }
    else if(n == 2){
        bool dk1 = a[left] % 2 == 0;
        bool dk2 = a[right] % 2 == 0;
        if(dk1 && dk2)
            return a[left] < a[right] ? left : right;
        if(dk1)
            return left;
        if(dk2)
            return right;
    }else if(n > 2){
        int mid = (left + right) / 2;
        int i1 = min_chan(a, left, mid);
        int i2 = min_chan(a, mid + 1, right);
        if(i1 != -1 && i2 != -1)
            return a[i1] < a[i2] ? i1 : i2;
        if(i1 != -1)
            return i1;
        if(i2 != -1)
            return i2;
    }
    return -1;
}

int main(){
    int a[] = {
        111, 6, 12, 18,
        21, 7, 13, 19,
        1, 8, 14, 20,
        3, 9, 15, 20,
        4, 10, 16, 22,
        5, 11, 17, 23
    };
    int n = 24;
    int i = min_chan(a, 0, n - 1);

    cout << a[i];

    return 0;
}