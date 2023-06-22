#include <iostream>
#include <queue>

using namespace std;

void quick_sort(float *s, float *f, int left, int right){
    if(left < right){
        // thiet lap moc k
        int k = (left + right) / 2;
        float t = f[k];
        // phan chia 
        int i = left, j = right;
        do{
            while(f[i] < t) i++;
            while(f[j] > t) j--;
            if(i <= j){
                float tg = s[i];
                s[i] = s[j];
                s[j] = tg;
                tg = f[i];
                f[i] = f[j];
                f[j] = tg;
                i++;j--;
            }
        }while(i <= j);
    }
}

queue<int> interval_scheduling(float *s, float *f, int n){
	quick_sort(s, f, 0, n - 1);
	queue<int> schedule;
	int last_finish = 0;
	for(int i = 0; i < n; i++){
		if(s[i] >= last_finish){
			schedule.push(i);
			last_finish = f[i];
		}
	}

	return schedule;
}

int main(int argc, char const *argv[])
{
    int n = 5;
    float s[] = {8, 9, 10, 11, 12};
    float f[] = {8.5, 11, 11.5, 12.5, 13};
  
	queue<int> schedule = interval_scheduling(s, f, n);
	
	if(schedule.size() == 0){
		cout << "Khong co cong viec nao duoc thuc hien.";
	}else{
		cout << "Danh sach cong viec: \n";
		queue<int> g = schedule;
		while (!g.empty()) {
	        cout << '\t' << s[g.front()];
	        g.pop();
	    }
	}
	
    return 0;
}
