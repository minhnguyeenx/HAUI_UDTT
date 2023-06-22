#include <bits/stdc++.h>

using namespace std;

//struct Time{
//	int minute;
//	int hour;
//};

struct Work{
	string id;
	string begin;
	string worktime;
};

void printAWork(Work a){
	cout << "ID: " << a.id << "\n";
//	cout << "Thoi gian bat dau: " << a.begin.hour <<":" <<a.begin.minute<< "\n";
//	cout << "Thoi gian thuc hien: " << a.timework.hour <<":" <<a.timework.minute<< "\n";
	cout << "Thoi gian bat dau: " << a.begin << "\n";
	cout << "Thoi gian thuc hien: " << a.worktime << "\n";
}

void hienthinguoc(Work *a, int n){
	if(n == 0) return;
	else {
		printAWork(a[n-1]);
		hienthinguoc(a, n-1);
	}
}

//Sinh hoan vi chap K cua N phan tu
void viewconfig_1(int k, int x[], Work *a){
	for(int i = 1; i <= k; i++){
		cout << a[x[i]-1].id << " ";
	}
	cout << endl;
}
void nextconfig_1(int k, int x[], int i){
	x[i] = x[i]+1;
	i++;
//	int j = k;
	while(i <= k){
		x[i] = x[i-1]+1;
		i++;
	}
}
void listconfig_1(int n, int k, Work *a){
	int i;
	int x[n+1] = {0};
	for(int i = 1; i <= k; i++){
		x[i] = i;
	}
	do{
		viewconfig_1(k, x, a);
		i = k;
		while(i > 0 && x[i] == n-k+i) i--;
		if(i > 0) nextconfig_1(k, x, i);
	}while(i > 0);
}

//Sinh hoan vi cua N
void nextconfig_3(int n, int x[], int i){
	int k = n;
	while(x[k] < x[i]) k--;
	swap(x[k], x[i]);
	int j = n; i++;
	while(i <= j){
		swap(x[i], x[j]);
		i++; j--;
	}
}

void listconfig_3(int n, Work *a){
	int i;
	int x[n+1] = {0};
	for(int i = 1; i <= n; i++){
		x[i] = i;
	}
	do{
		viewconfig_1(n, x, a);
		i = n-1;
		while(i > 0 && x[i] > x[i+1]) i--;
		if(i > 0) nextconfig_3(n, x, i);
	}while(i > 0);
}

//Quay lui to hop chap k cua n phan tu
void Try_1(int n, int k, int x[], Work *a, int start, int size){
	if(size == k){
		for(int i = 0; i < k; i++){
		cout << a[x[i]-1].id << " ";
		}
		cout << endl;
	} else{
		for(int i = start; i <= n; i++){
			x[size] = i;
			Try_1(n, k, x, a, i+1, size+1);
		}
	}
}

//Quay lui hoan vi n phan tu
void Try_2(int n, int k, int x[], Work *a, int check[]){
	for(int i = 1; i <=n; i++){
		if(check[i] == 0){
			x[k] = i;
			if(k == n) {
				for(int i = 1; i <= n; i++){
					cout << a[x[i]-1].id << " ";
				}
				cout << endl;
			}
			else{
				check[i] == 1;
				Try_2(n, k+1, x, a, check);
				check[i] == 0;
			}
		}
	}
}

int main(){
	int n = 6;
	Work *a = new Work[n];
//	a[0] = {"W001", time1, time1};
	a[0] = {"W001", "12:30", "01:30"};
	a[1] = {"W002", "12:30", "00:30"};
	a[2] = {"W003", "12:30", "02:30"};
	a[3] = {"W004", "12:30", "04:30"};
	a[4] = {"W005", "12:30", "00:30"};
	a[5] = {"W006", "12:30", "02:30"};
//	printAWork(a[0]);
//	cout << "Hien thi danh sach cong viec duoi dang nguoc lai\n";
//	hienthinguoc(a, n);
	
//	cout << "\nTat ca cac phuong an lay ra 5 cong viec la: \n";
//	int k = 5;
//	listconfig_1(n, k, a);

//	cout << "\nTat ca cac phuong an lay ra 6 cong viec lan luot la: \n";
//	listconfig_3(n, a);
//	
	int x[n+1] = {0}, check[n+1] = {0};
	
//	cout << "\nTat ca cac phuong an lay ra 5 cong viec la: \n";
//	int k = 5;
//	Try_1(n, k, x, a, 1, 0);
	
//	cout << "\nTat ca cac phuong an lay ra 6 cong viec lan luot la: \n";
//	Try_2(n, 1, x, a, check);
}
