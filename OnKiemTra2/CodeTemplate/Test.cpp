#include <iostream>

using namespace std;

struct DT
{
    string nh;
    int kt;
    double gb;
};

double max(double a, double b)
{
    return a > b ? a : b;
}

void cai_tui(DT *d, double **f, int s, int n)
{
    for (int i = 0; i <= n; i++)
        f[0][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= s; j++)
            if (d[i].kt <= j)
                f[i][j] = max(f[i - 1][j], f[i - 1][j - d[i].kt] + d[i].gb);
            else
                f[i][j] = f[i - 1][j];
}

double result(DT*d, double **f, int s, int n){
    double gt = 0;
    int i = n, j = s;
    while(i != 0 && j != 0){
        if(f[i][j] != f[i-1][j]){
            cout << d[i].nh << "\t" << d[i].kt << "\t"<< d[i].gb << endl;
            j -= d[i].kt;
            gt += d[i].gb;
        }
        i--;
    }
    return gt;
}

int char_in_string(char x, string p)
{
    for (int i = p.length() - 1; i >= 0; i--)
        if (x == p[i])
            return i;
    return -1;
}

bool boyer(string p, string t)
{
    int i = p.length();
    while (i <= t.length())
    {
        int j = i - 1;
        int k = p.length() - 1;
        while (p[k] == t[j] && k > -1)
        {
            k--;
            j--;
        }
        if (k < 0)
        {
            return true;
        }
        else
        {
            k = char_in_string(t[j], p);
            if (k < 0)
                i += p.length();
            else
                i += p.length() - 1 - k;
        }
    }
    return false;
}

int main()
{
    int n = 6;

    DT *d = new DT[n + 1];
    d[1] = {"SamSung", 5, 900000};
    d[2] = {"Nokia", 3, 300000};
    d[3] = {"LG", 4, 600000};
    d[4] = {"Vsmart", 7, 700000};
    d[5] = {"Iphone", 5, 300000};
    d[6] = {"Bphone", 8, 120000};

    int s = 13;

    double **f = new double *[n + 1];
    for (int i = 0; i <= n; i++)
        f[i] = new double[s + 1];

    cai_tui(d, f, s, n);

    double gt = result(d, f, s, n);
    cout << "Tong gia tri: " << gt << endl;

    string name = "Vsmart";
    bool b = false;
    for (int i = 1; i < n + 1; i++)
        if (boyer(name, d[i].nh))
        {
            b = true;
            break;
        }
    if (b)
    {
        cout << "co " << name;
    }
    else
        cout << "Khong co " << name;
    return 0;
}

