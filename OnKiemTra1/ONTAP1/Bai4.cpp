#include <bits/stdc++.h>

using namespace std;

struct Flight{
	string id;
	float cost;
	int cnt;
};

void findcost(Flight *a, vector<Flight>&res, int l, int r){
	if(l == r){
		if(a[l].cost > 700000){
			res.push_back(a[l]);
		}
	} else{
		int m = (l+r)/2;
		findcost(a, res, l, m);
		findcost(a, res, m+1, r);
	}
}

int findMin(Flight *a, int l, int r){
	if(l == r){
		return l;
	} else{
		int m = (l+r)/2;
		int lmin = findMin(a, l, m);
		int rmin = findMin(a, m+1, r);
		if(a[lmin].cost < a[rmin].cost) return lmin;
		else return rmin;
	}
}

void view(Flight *a, int x[], int k){
	for(int i = 0; i < k; i++){
		cout << a[x[i]-1].id << " ";
	}
	cout << endl;
}

void Try(int n, int k, Flight *a, int x[], int start, int size){
	if(k == size){
		view(a, x, k);
	}
	else{
		for(int i = start; i <= n; i++){
			x[size] = i;
			Try(n, k, a, x, i+1, size+1);
		}
	}
}


//TO HOP CHAP K
void nextconfig_1(int k, int x[], int i){
	//1236 -> 1246
	x[i] = x[i]+1; i++;
	//1246->1245
	while(i <= k){
		x[i] = x[i-1]+1;
		i++;
	}
}

void listconfig_1(int n,int k, Flight *a){
	int i;
	int x[n+1];
	for(int i = 1; i <= k; i++){
		x[i] = i;
	}
	do{
//		viewconfig(k, x);
//		view(a, x, k);
		for(int i = 1; i <= k; i++){
			cout << a[x[i]-1].id << " ";
		}
		cout << endl;
		i = k;
		while(i> 0 && x[i] == n-k+i){
			i--;
		}
		if(i > 0){
			nextconfig_1(k, x, i);
		}
	}while(i > 0);
}

//HOAN VI
void nextconfig_2(int x[], int n, int i){
	//136542
	//->
	int k = n;
	while(x[k] < x[i]) k--;
	swap(x[i], x[k]);
	int  j = n; i++;
	while(i < j){
		swap(x[i], x[j]);
		i++; j--;
	}
	
}

void listconfig_2(int n, Flight *a){
	int i;
	int x[n+1];
	for(int i = 1; i <= n; i++){
		x[i] = i;
	}
	do{
		for(int i = 1; i <= n; i++){
			cout << a[x[i]-1].id << " ";
		}
		cout << endl;
		i = n-1;
		while(i > 0 &&x[i] > x[i+1]) i--;
		if(i > 0) nextconfig_2(x, n, i);
	}while(i > 0);
}

int main(){
	int n;
	n = 6;
	Flight *a = new Flight[n];
	a[0] = {"VN001", 2000000, 30};
	a[1] = {"VN002", 100000, 40};
	a[2] = {"VN003", 300000, 50};
	a[3] = {"VN004", 5000000, 40};
	a[4] = {"VN005", 300000, 20};
	a[5] = {"VN006", 4000000, 60};
	
	cout << "\nCac chuyen bay co gia lon hon 700000: ";
	vector<Flight> res;
	findcost(a, res, 0, n-1);
	if(res.size() == 0){
		cout << "Khong co chiec nao";
	} else{
		for(int i = 0; i < res.size(); i++){
			cout << res[i].id << " ";
		}
	}
	
	cout << "\nChuyen bay co gia thap nhat: ";
	int kq = findMin(a, 0, n-1);
	cout << a[kq].id << endl;
	
	int k = 4;
//	int x[k+1];
//	cout << "Tat ca cac phuong an khac nhau de chon 4 chuyen bay: \n";
//	Try(n, k, a, x, 1, 0);
	
	cout << "Tat ca cac phuong an khac nhau de chon 4 chuyen bay(Cach 2): \n";
	listconfig_1(n, k, a);
	
	cout << "Thu tu xuat phat co the co: ";
	listconfig_2(n, a);
}
