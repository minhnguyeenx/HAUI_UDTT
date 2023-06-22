#include <iostream>

using namespace std;

void quick_sort(int *a, int left, int right)
{
    if (left < right)
    {
        // xac dinh moc k
        int k = (left + right) / 2;
        int t = a[k];
        // phan chia
        int i = left, j = right;
        do
        {
            while (a[i] > t)
                i++;
            while (a[j] < t)
                j--;
            if (i <= j)
            {
                int tg = a[i];
                a[i] = a[j];
                a[j] = tg;
                i++;
                j--;
            }
        } while (i <= j);
        quick_sort(a, left, j);
        quick_sort(a, i, right);
    }
}

int pouring(int jug, int *bottle, int m, int *S)
{
    // khoi tao mang solution
    for (int i = 0; i < m; i++)
    {
        S[i] = 0;
    }
    // xap xep giam dan theo dung tich
    quick_sort(bottle, 0, m - 1);
    int i = 0;
    for (; i < m; i++)
        while (i < m && jug >= bottle[i])
        {
            // do nuoc tu binh vao chai
            jug -= bottle[i];
            S[i]++;
        }
    cout << "Con " << jug << " lit nuoc.\n";
    return i;
}

int main()
{
    int n = 10;
    int m = 5;
    int bottle[] = {8, 5, 4, 3, 2};
    int *S = new int[m];

    int number = pouring(n, bottle, m, S);
    if (number > 0)
    {
        cout << "Phuong an: \n";
        for (int i = 0; i < number; i++)
        {
            cout << S[i] << " binh " << bottle[i] << " lit\n";
        }
    }
    else
    {
        cout << "Khong co phuong an.";
    }

    return 0;
}