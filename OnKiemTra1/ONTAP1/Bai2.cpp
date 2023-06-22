#include <bits/stdc++.h>

using namespace std;

void viewconfig(int k, int x[],char label[]){
	for(int i = 1; i <= k; i++){
		cout << label[x[i]-1];
	}
	cout << endl;
}

void nextconfig(int k, int x[], int i){
	x[i] = x[i] + 1;
	i++;
	int j = k;
	while(i <= j){
		x[i] = x[i-1]+1;
		j--;
		i++;
	}
}

void listconfig(int n, int k, char label[]){
	int i;
	int x[n+1] = {0};
	for(int i = 1; i <=k; i++){
		x[i] = i;
	}
	do{
		viewconfig(k, x, label);
		i = k;
		while(i > 0 && x[i] == n-k+i) i--;
		if(i > 0) nextconfig(k, x, i);
	}while(i > 0);
}

void Try(int k, int n, int x[], int start, int size){
	if(size == k){
		for(int i = 0; i < k; i++){
			cout << x[i];
		}
		cout << "\n";
	} else{
		for(int i = start; i <= n; i++){
			x[size] = i;
			Try(k, n, x, i+1, size+1);
		}
	}
}

void view(int n, int k, int x[]){
	for(int i = 0; i < k; i++){
		cout << x[i];
	}
	cout << "\n";
}


int main(){
	int n, k;
	n = 7, k= 6;
	char label[] = {'A', 'B', 'C', 'D', 'E','F', 'G'};
	cout << "\nSu dung phuong phap sinh\n";
//	listconfig(n, k, label);
	
	int x1[k+1] = {0};
	cout << "\nSu dung quay lui\n";
	Try(k, n, x1, 1, 0);
}
