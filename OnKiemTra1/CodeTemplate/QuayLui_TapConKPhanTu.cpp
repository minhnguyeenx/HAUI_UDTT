#include <iostream>

using namespace std;

void view(int n, int k, int x[]){
	for(int i = 0; i < k; i++){
		cout << x[i];
	}
	cout << "\n";
}

void Try(int k, int n, int x[], int start, int size){
	if(size == k){
		view(n, k, x);
//		return;
	} else{
		//size dem so luong phan tu da chon
		//bien start dam bao 1 phan tu khong duoc chon 2 lan
		for(int i = start; i <= n; i++){
			x[size] = i;
			//start start = i+1
			//size = size +1
			Try(k, n, x, i+1, size+1);
		}
	}
}

int main(){
	int n;
	n = 6;
	int k = 4;
	int x[k+1] = {0};
	Try(k, n, x, 1, 0);
}
