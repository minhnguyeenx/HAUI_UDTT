#include <iostream>
using namespace std;

// Hàm hoán d?i ph?n t?
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Hàm chính c?a QuickSort
 a[] --> mang can sap xep,*/
void quickSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        int pivot = a[m];
        int i = l, j = r;
        do {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            if (i <= j) {
                swap(&a[i], &a[j]);
                //PHAI CO I++, J-- de no con xet cac so sau
				//NHO LAY
                i++;
                j--;
            }
        } while (i <= j);

        quickSort(a, l, j);
        quickSort(a, i, r);
    }
}

// Hàm hien thi mang
void display(int a[], int size) {
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Hàm main
int main() {
    int a[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, n - 1);
    cout << "Mang da sap xep: \n";
    display(a, n);
    return 0;
}
