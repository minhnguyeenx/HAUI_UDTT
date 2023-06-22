#include <bits/stdc++.h>

using namespace std;

void mergeSort(float a[], int l, int r) {
    if (r > l) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        float b[r + 1];
        for (int i = l; i <= m; i++) {
            b[i] = a[i];
        }
        for (int j = m + 1; j <= r; j++) {
            b[r + m + 1 - j] = a[j];
        }

        // Tron mang b vao mang a
        int i = l;
        int j = r;
        for (int k = l; k <= r; k++) {
            if (b[i] < b[j]) {
            	//b[i] > b[j]: giam dan
                a[k] = b[i];
                i++;
            } else {
                a[k] = b[j];
                j--;
            }
        }
    }
}

void printArray(float a[], int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}

int main(){
	float a[15] = {0, 1, 2, 3, 5, 20, 140, 22, 13, 15,10, 11, 12, 30, 5};
	mergeSort(a, 0, 14);
	printArray(a, 14);
}
