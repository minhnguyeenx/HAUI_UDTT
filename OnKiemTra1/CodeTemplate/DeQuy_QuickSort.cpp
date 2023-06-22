#include <iostream>
using namespace std;

// Hàm hoán d?i ph?n t?
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(int* a, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        int pivot = a[mid];
        int i = left, j = right;

        do {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            if (i <= j) {
                swap(&a[i], &a[j]);
                i++;
                j--;
            }
        } while (i <= j);

        quickSort(a, left, j);
        quickSort(a, i, right);
    }
}

// Hàm hi?n th? m?ng
void display(int* a, int size) {
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Hàm main
int main() {
    int n;
//    cout << "Nhap so luong phan tu: ";
//    cin >> n;
	n = 5;
    int* a = new int[n];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = -2;
    a[4] = 6;
//    for (int i = 0; i < n; i++) {
//        cout << "Nhap phan tu thu " << i + 1 << ": ";
//        cin >> a[i];
//    }
    quickSort(a, 0, n - 1);
    cout << "Mang da sap xep: \n";
    display(a, n);
    delete[] a;
    return 0;
}
