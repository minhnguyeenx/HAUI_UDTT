#include <iostream>
#include <string>

using namespace std;

struct Sach{
	string ten;
	string nxb;
	int so_trang;
};

void merge_sort(Sach sa[], Sach tam[], int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		merge_sort(sa, tam, left,mid);
		merge_sort(sa, tam, mid + 1, right);
		
		for(int i = left; i <= mid; i++) tam[i] = sa[i];
		for(int i = right; i > mid; i--) tam[right - i + mid + 1] = sa[i];
		// tron lai
		int i = left, j = right;
		for (int k = left; k <= right; k++)
		{
			if(tam[i].ten < tam[j].ten){
				sa[k] = tam[i];
				i++;
			}else{
				sa[k] = tam[j];
				j--;
			}
		}
	}
}

void xuat(Sach sa[], int n){
	for(int i = 0; i < n; i++)
		cout << sa[i].ten << "|" << sa[i].nxb << "|" << sa[i].so_trang << "\n";
}

int main(){
	Sach sa[] = {
		{"Nguoi thanh cong", "Kim dong", 105},
		{"Tay du ky", "Kim Dung", 954},
		{"Thuy tien", "Kim Dung", 751},
		{"De men phieu luu ky", "To Hoai", 241},
		{"Dau tu viec hoc", "Nhan Tuan", 264},
		{"Doanh nhan", "Tran Huong", 134},
		{"Trung khoan can ban", "Quang Huy", 587},
		{"Ban la nang", "Nguyen The Hoang", 521},
		{"Dan chu", "Duong Phuong", 564},
		{"Mot la mot", "Trinh Phuong", 235},
	};

	int n = 10;

	Sach *tam = new Sach[n];

	merge_sort(sa, tam,0, n - 1);

	xuat(sa, n);

	return 0;
}