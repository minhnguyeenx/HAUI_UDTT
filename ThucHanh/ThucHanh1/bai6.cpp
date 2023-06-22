#include <iostream>
#include <string>

using namespace std;

int n = 6;
string arr[6] = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};

void view_config()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << "\n";
}

void swap(string &a, string &b)
{
    string tg = a;
    a = b;
    b = tg;
}

bool next_config()
{
    // khoi tao
    int travel = n - 2;

    while (travel >= 0 && arr[travel] > arr[travel + 1])
        travel--;

    if (travel < 0)
        return false;

    // doi cho
    int j = n - 1;

    while (arr[j] <= arr[travel])
    {
        j--;
    }

    swap(arr[j], arr[travel]);
    travel++;

    // dao nguoc chuoi con lai
    j = n - 1;
    while (travel < j)
    {
        swap(arr[travel], arr[j]);
        travel++;
        j--;
    }

    return true;
}

void listing_configs()
{
    do
    {
        view_config();
    } while (next_config());
}

void sort()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
}

int main(int argc, char const *argv[])
{
    sort();
    listing_configs();

    return 0;
}