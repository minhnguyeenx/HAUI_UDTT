#include <iostream>

using namespace std;

void view(int x[], int n){
	for(int i = 1; i <= n; i++){
		cout << x[i];
	}
	cout << "\n";
}

void Try(int k, int n, int x[]){
	for(int i = 0; i <= 1; i++){
		x[k] = i;
		if(k == n) view(x, n);
		else{
			Try(k+1, n, x);
		}
	}
}

int main(){
	int n;
	n = 4;
	int x[n+1] = {0};
	Try(1, n, x);
}
