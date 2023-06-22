#include <iostream>

using namespace std;

void view(int n, int x[]){
	for(int i = 1; i <= n; i++){
		cout << x[i];
	}
	cout << "\n";
}

void Try(int k, int n, int x[], int check[]){
	// chay k lan luot tu 1 den n(hoan vi)
	for(int i = 1; i <= n; i++){
		//check xem i duoc xet hay chua
		if(check[i] == 0){
			x[k] = i;
			if(k == n) view(n, x);
			else{
				check[i] = 1;
				Try(k+1, n, x, check);
				check[i] = 0;
			}
		}
	}
}

int main(){
	int n;
	n = 5;
	int check[n+1] = {0}, x[n+1] = {0};
	Try(1, n, x, check);
}
