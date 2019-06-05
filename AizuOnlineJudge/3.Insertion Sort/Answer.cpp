#include<iostream>
using namespace std;

void trace(int A[], int N);
	void insertionSort(int A[], int N);

int main() {
	int N; //要素数
	int A[100]; //数列配列

	//入力
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	//計算
	trace(A, N);
	insertionSort(A, N);

	return 0;
}

//配列の要素を順番に出力
void trace(int A[], int N) {
	for (int i = 0; i < N; i++) {
		if (i > 0) { cout << " "; }
		cout << A[i];
	}
	cout << endl;
}

//挿入ソート（０オリジン配列）
void insertionSort(int A[], int N) {
	int j, v;
	for (int i = 1; i < N; i++) {
		v = A[i];
		j = i - 1; //(move)
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		trace(A, N);
	}
}