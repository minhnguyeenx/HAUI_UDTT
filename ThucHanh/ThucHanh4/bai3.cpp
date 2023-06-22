#include <iostream>

using namespace std;

void xuat(float ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ds[i] << "\t";
    }
    cout << endl;
}

int max(float ds[], int left, int right){
    int n = right - left + 1;
    if(n <= 2)
        return ds[left] > ds[right] ? left : right;
    else{
        int mid = (left + right) / 2;
        int i1 = max(ds, left, mid);
        int i2 = max(ds, mid + 1, right);
        return ds[i1] > ds[i2] ? i1 : i2;
    }
}

int main()
{
    float ds[] = {
        0.1,
        11.0,
        1.2,
        12.2,
        2.2,
        13.3,
        3.3,
        14.5,
        4.3,
        15.5,
        5.5,
        16.6,
        6.6,
        17.7,
        7.7,
        18.8,
        8.8,
        19.9,
        9.9,
        20.1,
        10.1,
        21.1,
    };

    int n = 22;

    xuat(ds, n);
    int i = max(ds, 0, n - 1);
    cout << "Max: " << ds[i];

    return 0;
}