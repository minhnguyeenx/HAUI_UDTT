#include <iostream>

using namespace std;

double tong_duong(float a[], int left, int right){
    if(left < right){
        if(a[right] > 0)
            return tong_duong(a, left, right - 1) + a[right];
        return tong_duong(a, left, right - 1);
    }
    return 0;
}

int main(){
    float a[] = {
        0.1, -5.2, 13.2,
        1.1, -6.2, 14.2,
        2.2, -7.2, 15.2,
        3.3, -8.0, 16.5,
        4.4, -9.0, 17.8,
        53.5, -10.2, 18.2,
        11.2, -12.2, 19.2,
    };
    int n = 21;
    
    cout << tong_duong(a, 0, n - 1);

    return 0;
}