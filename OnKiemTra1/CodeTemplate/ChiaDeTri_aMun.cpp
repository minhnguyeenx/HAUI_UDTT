#include <iostream>

using namespace std;

float pow(float a, int n){
	if(n==1) return a;
	if(n%2 == 0) return pow(a, n/2) * pow(a, n/2);
	else return a*pow(a, n/2) * pow(a, n/2);
}

int main(){
	float a;
	int n;
	cout << pow(2, 3);
}
