#include <iostream>

using namespace std;

struct HocSinh
{
    string ten;
    string msv;
    int tuoi;
};

int max(HocSinh hs[], int left, int right)
{
    int n = right - left + 1;
    if (n <= 2)
    {
        return hs[left].ten > hs[right].ten ? left : right;
    }
    else
    {
        int mid = (left + right) / 2;
        int i1 = max(hs, left, mid);
        int i2 = max(hs, mid + 2, right);
        return hs[i1].ten > hs[i2].ten ? i1 : i2;
    }
}

int main()
{
    HocSinh hs[] = {
        {"Le Duc Tiep", "2020603171", 20},
        {"Tran Thi Thuy", "202056548", 20},
        {"Nguyen Xuan Tien", "20125489", 20},
        {"Tran Xuan Tien", "205486502", 20},
        {"Le Thi Nga", "2021524875", 20},
        {"Nguyen Viet Tien", "2022515487", 20},
        {"Nguyen Thi Thuong", "2020359481", 20},
        {"Tran Thi Thuy", "2020154224", 20},
        {"Nguyen Thi Minh", "2020554488", 20},
        {"Le Thi La", "2020326548", 20},
        {"Nguyen Duy Sang", "2020546468", 20},
        {"Dang Thuc Thang", "2020564658", 20},
        {"Tran Bao Danh", "2020565548", 20},
        {"Nguyen Thi Trinh", "2020564685", 20},
        {"Luu Ngoc Anh", "2020564747", 20},
        {"Nguyen Thi Khanh Minh", "2020546854", 20},
        {"Nguyen Minh Anh", "2020154215", 20},
        {"Vu Thi Lan Anh", "20204547846", 20},
        {"Vu Thi Thuong", "202025655851", 20},
        {"Vu Thi Truong", "2020658475", 20},
        {"Tran Van Tuan", "2020565666", 20},
        {"Luu Anh", "2020565544552", 20},
        {"Pham Thi Thu", "2020555544", 20},
        {"Pham Thi Thuy", "2020840221", 20},
    };

    int n = 24;

    int i = max(hs, 0, n - 1);

    cout << "==============Hoc sinh co ten max===================\n";
    cout << hs[i].ten << "|" << hs[i].msv << "|" << hs[i].tuoi << "\n";

    return 0;
}