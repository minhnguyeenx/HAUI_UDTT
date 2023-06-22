#include <iostream>
#include <stack>

using namespace std;

struct Move{
	int n;
	char a, b, c;
	bool operator < (const Move &other) const {return n < other.n;}
};

void move(int n, char a, char b, char c){
	cout << "Di chuyen tu " << a << " sang " << c << "\n";
}

//a->b
//a->c
//b->c

void Tower(int n, char a, char b, char c){	
	stack<Move> st;
	st.push({n, a, b, c});
	while(!st.empty()){
		Move cm  = st.top();
		st.pop();
		if(cm.n == 1){
			move(1, cm.a, cm.b, cm.c);
		}
		else{
			st.push({cm.n-1, cm.b, cm.a, cm.c});
			st.push({1, cm.a, cm.b, cm.c});
			st.push({cm.n-1, cm.a, cm.c, cm.b});
		}
	}
}

int main(){
	int n;
	n = 4;
	Tower(n, 'A', 'B', 'C');
}
	
