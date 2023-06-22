#include <iostream>

using namespace std;

void merge_sort(float a[], float *tam, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        // phan chia
        merge_sort(a, tam, left, mid);
        merge_sort(a, tam, mid + 1, right);
        // chep nua dau
        for (int i = left; i <= mid; i++)
            tam[i] = a[i];
        // chep nua sau
        for (int i = right; i > mid; i--)
            tam[right - i + mid + 1] = a[i];
        // tron
        int i = left, j = right;
        for (int k = left; k <= right; k++)
            if (tam[i] < tam[j])
            {
                a[k] = tam[i];
                i++;
            }
            else
            {
                a[k] = tam[j];
                j--;
            }
    }
}

void xuat(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main()
{
    float a[] = {
        0.1, 9.0,
        1.2, 10.2,
        2.5, 11.2,
        3.5, 12.2,
        4.2, 13.3,
        5.6, 14.2,
        6.5, 15.5,
        7.9, 16.5,
        8.1, 17.8};
    int n = 18;
    float *tam = new float[n];

    merge_sort(a, tam, 0, n - 1);

    xuat(a, n);

    return 0;
}