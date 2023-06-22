#include <iostream>

using namespace std;

void view_config(int cf[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (cf[i] == 0)
        {
            break;
        }
        cout << cf[i] << "\t";
    }
    cout << endl;
}

bool la_giam_dan(int cf[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (cf[i] < cf[i + 1])
            return false;
    }
    return true;
}

bool next_config(int cf[], int m, int n)
{

    cf[0] = m;
    for (int i = 1; i < n; i++)
    {
        m -= cf[i - 1];
        if (m < 0)
            break;
        cf[i] = m;
    }
    view_config(cf, n);
start:
    for (int i = n - 1; i > -1; i--)
    {
        if (cf[i] > 1)
        {
            cf[i]--;
            cf[i + 1]++;
            // if (!la_giam_dan(cf, n))
            if (cf[i] < cf[i + 1])
            {
                goto start;
                cout << "-------------------------------";
            }
            int x = cf[0];
            if (cf[0] != m)
                break;
            return true;
        }
    }

    return false;
}

void listing_config(int cf[], int m, int n)
{
    if (m > n)
        m = n;
    int i = 1;
    do
    {
        cout << "Cach " << i++ << ": ";
        view_config(cf, n);
    } while (next_config(cf, m, n));
}

int main()
{
    int n = 11;
    int m = n;
    int *cf = new int[n];
    cf[0] = m;
    for (int i = 1; i < n; i++)
    {
        cf[i] = 0;
    }
    listing_config(cf, m, n);

    return 0;
}