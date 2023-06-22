#include <bits/stdc++.h>

using namespace std;

//char label[4] = {'0', 'A', 'B', 'C', 'D'};
//string name[4] = {"0", "Tung", "Cuc", "Truc", "Mai"};

void swap(string &a, string &b){
	string tg = a;
	a = b;
	b = tg;
}

void view_config(int n, char label[], string name[]){
	for(int i = 1; i <= n; i++){
		cout << label[i] << "-" << name[i] << " ";
	}
	cout << endl;
}

void next_config(int n, string name[], int i){
	int k = n;
	while(name[k] < name[i]){
		k--;
	}
	swap(name[k], name[i]);
	int j = n; i++;
	while(i < j){
		swap(name[i], name[j]);
		i++; j--;
	}
}

void list_config(int n, int &cnt, char label[], string name[]){
	int i;
	do{
		view_config(n, label, name);
		i = n-1;
		while(i > 0 && name[i] > name[i+1]){
			i--;
		}
		if(i > 0){
			next_config(n, name, i);
			cnt++;
		}
	}while(i > 0);
}

void Try(int k, int n, char label[], string name[], int check[], int &cnt){
	for(int i = 1; i <= n; i++){
		if(check[i] == 0){
			label[k] = (char)(i+64);
			if(k == n) {
				cnt++;
				view_config(n, label, name);
			}
			else{
				check[i] = 1;
				Try(k+1, n, label, name, check, cnt);
				check[i] = 0;
			}
		}
	}
}

int main(){
	int n;
	n = 4;

	char label[5] = {'0', 'A', 'B', 'C', 'D'};
	string name[5] = {"0","Cuc", "Mai", "Truc", "Tung"};
	int check[5] = {0};
	
	//Cach 1: Sinh hoan vi(Liet ke hoan vi)
	int cnt = 1;
	list_config(n, cnt, label, name);

	//Cach 2: Quay lui
//	int cnt = 0;
//	Try(1, n, label, name, check, cnt);
	cout << "Tong so sach sap xep: " << cnt << endl;
}
