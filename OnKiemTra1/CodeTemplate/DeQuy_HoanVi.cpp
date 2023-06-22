#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b){
	int tg = a;
	a = b;
	b = tg;
}

void viewconfig(int n, int x[]){
	for(int i = 1; i <= n; i++){
		cout << x[i] ;
	}
	cout << "\n";
}

void nextconfig(int n, int x[], int i){
	//Tim so dau tien lon hon x[i]
	int k = n;
	while(x[k]<x[i]){
		k--;
	}
	swap(x[i], x[k]); // doi
	
	//sap xep lai day
	int j = n; i++;
	while(i < j){
		swap(x[i], x[j]);
		i++; j--;
	}
}

void listconfig(int n){
	int i;
	int x[n+1] = {0};
	for(int i = 1; i <= n; i++){
		x[i] = i;
	}
	do{
		viewconfig(n, x);
		i = n-1;
		while(i > 0 && x[i] > x[i+1]){
			i--;
		}
		if(i > 0){
			nextconfig(n, x, i);
		}
	}while(i > 0);
}

int main(){
	int n;
	n = 5;
	listconfig(n);
	
}
