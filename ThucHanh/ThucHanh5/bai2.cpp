#include <iostream>

using namespace std;

void phan_tich(int **f, int m, int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if(i > j){
                f[i][j] = f[i-1][j];
            }else{
                f[i][j] = f[i-1][j] + f[i][j-i];
            }
        }
    }
}

int main(){
    int n = 5;
    int m = 5;

    int **f = new int*[n+1];
    for (int i = 0; i <= n; i++)
    {
        f[i] = new int[m+1];
    }

    f[0][0] = 1;
    for (int i = 1; i < m + 1; i++)
    {
        f[0][i] = 0;
    }

    phan_tich(f, m, n);

    cout << "So cach phan tich: " << f[n][m] << endl;



    return 0;
}