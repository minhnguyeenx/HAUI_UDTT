#include <bits/stdc++.h>

using namespace std;

int ucln1(int a, int b){
	if(b == 0) return a;
	return ucln1(b, a%b);
}

int ucln2(int a, int b){
	while(b != 0){
		int tg = a%b;
		a = b;
		b = tg;
	}
	return a;
}

int main(){
	int a = 15, b = 20;
	cout << ucln1(b, a) << "\n";
	cout << ucln2(b+1, a);
}
