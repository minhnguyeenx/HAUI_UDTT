#include <iostream>

using namespace std;

double luy_thua(float a, int n){
    if(n == 0)
        return 1;
    double half = luy_thua(a, n / 2);
    if(n % 2 == 0){
        return half * half;
    }else{
        return half * half * a;
    }
}

int main(){
    float a = 2;
    int n = 1;

    cout << luy_thua(a, n);

    return 0;
}