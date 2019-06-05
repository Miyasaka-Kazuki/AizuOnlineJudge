#include<iostream>
using namespace std;

int shellSort(int A[], int n, int G[], int *m);
int insertionSort(int A[], int n, int g);

int main() {
	int A[1000000]; //配列
	int n; //要素数

	//入力
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	//計算
	int m;
	int G[1000000];
	int cnt = shellSort(A, n, G, &m);

	//出力
	cout << m << endl;
	for (int i = 0; i < m; i++) {
		if (i) cout << " ";
		cout << G[i];
	}
	cout << endl;
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		cout << A[i] << endl;
	}

	return 0;
}

int insertionSort(int A[], int n, int g) {
	int cnt = 0;
	for (int i = g; g < n; i++) {
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j -= g;
			cnt++;
		}
		A[j + g] = v;
	}
	return cnt;
}

int shellSort(int A[], int n, int G[], int *m) {
	int cnt = 0;
	int i, j;
	j = 0;
	for (i = n/2; i > 10; i /= 2) {
		G[j] = i;
			j++;
	}
	G[j] = 1;
	*m = j + 1;
	for (int k = 0; k < *m; k++) {
		cnt = insertionSort(A, n, G[k]);
	}

	return cnt;
}
