#include <bits/stdc++.h>

using namespace std;

void viewconfig(int k, int x[]){
	for(int i = 1; i <= k; i++){
		cout << x[i];
	}
	cout << "\n";
}

void nextconfig(int k, int x[], int i){
	//1236 -> 1246
	x[i] = x[i]+1; i++;
	//1246->1245
	while(i <= k){
		x[i] = x[i-1]+1;
		i++;
	}
}

void listconfig(int n, int k){
	int i;
	int x[n+1];
	for(int i = 1; i <= k; i++){
		x[i] = i;
	}
	do{
		viewconfig(k, x);
		i = k;
		while(i> 0 && x[i] == n-k+i){
			i--;
		}
		if(i > 0){
			nextconfig(k, x, i);
		}
	}while(i > 0);
}

int main(){
	int n, k;
	n = 6, k = 4;
	listconfig(n, k);
}
