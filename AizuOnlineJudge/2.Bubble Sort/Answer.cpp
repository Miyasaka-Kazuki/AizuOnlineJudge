#include<iostream>
using namespace std;

int bubbleSort(int A[], int N);

int main() {
	int A[100]; //数列配列
	int N; //要素数
	int sw; //スワップ回数（列の乱れ具合）

	//入力
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	//計算
	sw = bubbleSort(A, N);

	//出力
	for (int i = 0; i < N; i++) {
		if (i) { cout << " "; }
		cout << A[i];
	}
	cout << endl;
	cout << sw << endl;

	return 0;
}

//flagを用いたバブルソート
int bubbleSort(int A[], int N) {
	int sw = 0;
	bool flag = true;
	for (int i = 0; flag; i++) {
		flag = false;
		for (int j = N - 1; j > i; j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j-1]);
				flag = true;
				sw++;
			}
		}
	}
	return sw;
}
