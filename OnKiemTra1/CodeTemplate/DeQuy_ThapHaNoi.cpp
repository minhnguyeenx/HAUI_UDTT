#include <iostream>

using namespace std;

void Tower(int n, char a, char b, char c){
	if(n == 1){
		cout << "Di chuyen dia " << n << " tu " << a << " sang " << c << "\n";
		return;
	}
	Tower(n-1, a, c, b);
//	Tower(1, a, b, c);
	cout << "Di chuyen dia " << n << " tu " << a << " sang " << c << "\n";
	Tower(n-1, b, a, c);
	
}

int main(){
	int n = 4;
	char a = 'A', b = 'B', c = 'C';	
	Tower(n, a, b, c);
}
	
