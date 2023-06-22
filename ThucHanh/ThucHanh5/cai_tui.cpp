#include <iostream>

using namespace std;

struct GoiHang
{
    int w;
    double v;
};

double max(double a, double b)
{
    return a > b ? a : b;
}

void cai_tui(GoiHang ds[], double **f, int n, int m)
{
    for (int i = 0; i <= m; i++)
    {
        f[0][i] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        f[j][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ds[i].w <= j)
            {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - ds[i].w] + ds[i].v);
            }
            else
            {
                f[i][j] = f[i - 1][j];
            }
        }
    }
}

double truy_vet(GoiHang ds[], double **f, int n, int m)
{
    cout << "STT\tW\tV\n";
    double GT = 0;
    int i = n, j = m;
    while ((i != 0) && (j != 0))
    {
        if (f[i][j] != f[i - 1][j])
        {
            cout << i << "\t" << ds[i].w << "\t" << ds[i].v << endl;
            GT += ds[i].v;
            j -= ds[i].w;
        }
        i--;
    }
    return GT;
}

int main()
{
    int n = 6;
    GoiHang *ds = new GoiHang[n + 1];
    ds[1] = {1, 3};
    ds[2] = {10, 4};
    ds[3] = {20, 5};
    ds[4] = {19, 7};
    ds[5] = {13, 6};
    ds[6] = {40, 9};

    int m;
    cout << "Nhap m: ";
    cin >> m;

    double **f = new double *[n + 1];
    for (int i = 0; i <= n; i++)
        f[i] = new double[m + 1];

    cai_tui(ds, f, n, m);

    double GT = truy_vet(ds, f, n, m);

    cout << "Tong gia tri: " << GT;

    return 0;
}