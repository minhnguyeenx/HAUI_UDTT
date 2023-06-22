#include <bits/stdc++.h>

using namespace std;

void Tower(int n, char a, char b, char c){
	if(n == 1){
		cout << a << " ----> " << c << "\n";
		return;
	}
	Tower(n-1, a, c, b);
	Tower(1, a, b, c);
	Tower(n-1, b, a, c);
}

char rod[] = {'A', 'B', 'C'};
vector<stack<int> > stacks(3);  // 3 ngan xep cho 3 cot

void moveDisk(int a, int b){
	if(stacks[b].empty() || (!stacks[a].empty() && stacks[a].top() < stacks[b].top())){
		cout << "Chuyen dia " << stacks[a].top() << " tu dia " << rod[a] << " sang dia " << rod[b] << endl;
		stacks[b].push(stacks[a].top());
		stacks[a].pop();
	} else{
		moveDisk(b, a);
	}
}

void Tower_2(int n){
	cout << "Thap Ha Noi cho " << n << " dia \n";
	int rod1 = 0, rod2 = 1, rod3 = 2;
	for(int i = n; i > 0; i--){
		stacks[rod1].push(i);
	}
	int totalMoves = (1<<n) - 1;
	if(n%2 == 0){
		swap(rod2, rod3);
	}
	for(int i = 1; i <= totalMoves; i++){
		if(i%3 == 0){
			moveDisk(rod2, rod3);
		} else if(i%3 == 1){
			moveDisk(rod1, rod3);
		} else{
			moveDisk(rod1, rod2);
		}
	}
} 

int main(){
	int n;
	cin >> n;
	int moveDisks = (1<<n) -1;
	//Cach 1: De quy
//	char a = 'A', b = 'B', c = 'C';
//	Tower(n, a, b, c);

	//Cach 2: Khu de quy
	Tower_2(n);

//	cout << "Tong so lan di chuyen: " << moveDisks << endl;
}
