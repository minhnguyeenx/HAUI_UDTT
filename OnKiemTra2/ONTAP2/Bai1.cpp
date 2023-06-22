#include <bits/stdc++.h>

using namespace std;

struct quat{
	string hangSX;
	string mauSac;
	double giaBan;
};

void swap(quat &a, quat &b){
	quat tmp = a;
	a = b;
	b = tmp;
}

void quick_sort(quat *a, int n, int l, int r){
	if(l < r){
		int m = (l+r)/2;
		double p = a[m].giaBan;
		int i = l, j = r;
		do{
			if(a[i].giaBan < p) i++;
			if(a[j].giaBan > p) j--;
			if(i <= j){
				swap(a[i], a[j]);
				i++; j--;
			}
		}while(i <= j);
		quick_sort(a, n, l, j);
		quick_sort(a, n, i, r);
	}
}

int mua_quat(quat *a, int n, double p){
	int i = 0;
	int cnt = 0;
	while(p > 0 && i < n){
		if(p >= a[i].giaBan){
			p = p - a[i].giaBan;
			cnt++;
		}
		i++;
	}
	return cnt;
}

int main(){
	double p = 800000;
	int n = 6;
	quat *a = new quat[n];
	a[0] = {"Panasonic", "Den", 150000};
	a[1] = {"Panasonic", "Do", 160000};
	a[2] = {"Panasonic", "Trang", 170000};
	a[3] = {"Media", "Den", 100000};
	a[4] = {"Senko", "Den", 120000};
	a[5] = {"Asia", "Den", 800000};
	
	quick_sort(a, n, 0, n-1);
	
	for(int i = 0; i < n; i++){
		cout << a[i].hangSX << "-" << a[i].giaBan << "\n";
	}
	
	int res = mua_quat(a, n, p);
	if(res == 0){
		cout << "Khong mua duoc chiec quat nao\n";
	} else{
		cout << "So quat co the mua duoc la " << res << "\n";
		cout << "Cac quat do la: \n";
		for(int i = 0; i < res; i++){
			cout << a[i].hangSX << "-" << a[i].giaBan << ", ";
		}
		cout << endl;
	}
}
