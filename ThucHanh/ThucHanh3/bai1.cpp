#include <iostream>

using namespace std;

// void quick_sort(int *a, int left, int right)
// {
//     if (left < right)
//     {
//         // chon moc key
//         int k = (left + right) / 2;
//         int t = a[k];
//         // phan chia
//         int i = left, j = right;
//         do
//         {
//             while (a[i] > t)
//                 i++;
//             while (a[j] < t)
//                 j--;
//             if (i <= j)
//             {
//                 int tg = a[i];
//                 a[i] = a[j];
//                 a[j] = tg;
//                 i++;
//                 j--;
//             }
//         } while (i <= j);
//         quick_sort(a, left, j);
//         quick_sort(a, i, right);
//     }
// }

void quick_sort(int *a, int left, int right){
    if(left < right){
        int k = (left + right) / 2;
        int t = a[k];
        int i = left, j = right;
        do{
            while(a[i] > t)
                i++;
            while(a[j] < t)
                j--;
            if(i <= j){
                int tg = a[i];
                a[i] = a[j];
                a[j] = tg;
                i++;
                j--;
            }
        }while(i <= j);
        quick_sort(a, left, j);
        quick_sort(a, i, right);
    }
}

bool cashiers_algorithm(int *C, int m, long n, int *S)
{
    // khoi tao S
    int i;
    for (i = 0; i < m; i++)
    {
        S[i] = 0;
    }
    // xap xep C
    quick_sort(C, 0, m - 1);

    i = 0;

    while (n > 0 && i < m)
    {
        S[i] = n / C[i];
        n %= C[i];
        i++;
    }
    return n > 0 ? false : true;
}

int main(int argc, char const *argv[])
{
    int C[] = {7, 6, 3, 2, 8, 9};
    int m = 6;
    int n = 97;
    int *S = new int[m];

    bool done = cashiers_algorithm(C, m, n, S);
    if (done)
    {
        cout << "Giai phap cua bai toan: \n";
        for (int i = 0; i < m; i++)
        {
            cout << S[i] << " dong " << C[i] << "\n";
        }
    }
    else
    {
        cout << "Khong tim duoc loi giai!";
    }
    return 0;
}
