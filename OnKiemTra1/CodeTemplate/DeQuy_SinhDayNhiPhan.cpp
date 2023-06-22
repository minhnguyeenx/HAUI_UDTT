#include <bits/stdc++.h>

using namespace std;


void viewconfig(int n, int x[]){
	for(int i = 1; i <= n; i++){
		cout << x[i] ;
	}
	cout << "\n";
}

void nextconfig(int n, int x[], int i){
	x[i] = 1;
	i++;
	while(i <= n){
		x[i] = 0;
		i++;
	}
}

void listconfig(int n){
	int i;
	int x[n+1] = {0};
	do{
		viewconfig(n, x);
		i = n;
		//Tim so 0 dau tien
		while(i > 0 && x[i] == 1){
			i--;
		}
		if(i > 0){
			nextconfig(n, x, i);
		}
	}while(i> 0);
}

int main(){
	int n;
	n = 3;
//	int * = new int[n+1];
	listconfig(n);
	
}
