#include <iostream>
#include <string>

using namespace std;

struct HocSinh{
    string ten;
    string hoDem;
    int namSinh;
    string diaChi;
    HocSinh(){}
    HocSinh(string t, string hd, int ns, string dc){
        ten = t;
        hoDem = hd;
        namSinh = ns;
        diaChi = dc;
    }
    string out(){
        return ten +"\t|\t"+ hoDem +"\t|\t"+ to_string(namSinh) +"\t|\t"+ diaChi;
    }
    static string title(){
        return "Ten\t|\tHoDem\t|\tNamSinh\t|\tDiaChi";
    }
};

void quick_sort(HocSinh danhSach[], int left, int right){
    if(left < right){
        // xac dinh moc
        int k = (left + right) / 2;
        string t = danhSach[k].ten;
        // phan chia
        int i = left, j = right;
        do{
            while(danhSach[i].ten < t) i++;
            while(danhSach[j].ten > t) j--;
            if(i <= j){
                HocSinh hs = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = hs;
                i++;j--;
            }
        }while(i <= j);
        quick_sort(danhSach, left, j);
        quick_sort(danhSach, i, right);
    }
}

void xuat_danh_sach(HocSinh danhSach[], int n){
    cout << HocSinh().title() << endl;
    for(int i = 0; i < n; i++){
        cout << danhSach[i].out() << endl;
    }
}

int tim_kiem(HocSinh danhSach[], int left, int right, string ten){
    if(left <= right){
        int mid = (left + right) / 2;
        if(danhSach[mid].ten == ten)
            return mid;
        if(danhSach[mid].ten > ten)
            return tim_kiem(danhSach, left, mid - 1, ten);
        return tim_kiem(danhSach, mid + 1, right, ten);
    }else{
        return -1;
    }
}

int main(){
    HocSinh danhSach[] = {
        {"Toan", "Van", 2001, "Nam Dinh"},
        {"Tuan", "Vu", 2000, "Ha Noi"},
        {"Huan", "Song", 2002, "Ha Nam"},
        {"Nam", "Toan", 2003, "Bac Ninh"},
        {"Ninh", "Le", 2001, "Quang Ninh"},
        {"Trinh", "Dinh", 2002, "Ha Noi"},
        {"Hoang", "Ly", 2001, "Nam Sinh"},
        {"Vinh", "Tran", 2001, "Vinh"},
    };
    int n = 8;
    cout << "==================DANH SACH TRUOC KHI XAP XEP=======================" << endl;
    xuat_danh_sach(danhSach, n);
    cout << "==================DANH SACH SAU KHI XAP XEP=========================" << endl;
    quick_sort(danhSach, 0, n - 1);
    xuat_danh_sach(danhSach, n);

    // Nhap ten mot hoc sinh
    string ten = "Ninh";
    int index = tim_kiem(danhSach, 0, n - 1, ten);
    if(index == -1){
        cout << "Tim kiem that bai!" << endl;
    }else{
        cout << "============THONG TIN HOC SINH TIM THAY================" << endl;
        cout << HocSinh().title() << endl;
        cout << danhSach[index].out() << endl;
    }



    return 0;
}