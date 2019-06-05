#include<iostream>
using namespace std;

int selectionSort(int A[], int N);

int main() {
	int A[100]; //数列配列
	int N; //数列配列の長さ

	//入力
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	//計算
	int count; //交換回数
	count = selectionSort(A, N);

	//出力
	for (int i = 0; i < N; i++) {
		if (i) { cout << " "; }
		cout << A[i];
	}
	cout << endl;
	cout << count << endl;
	return 0;
}

//０オリジン配列を用いた昇順に並び替える選択ソート
int selectionSort(int A[], int N) {
	int count = 0;
	for (int i = 0; i < N - 1; i++) {
		int minj = i;
		for (int j = i + 1; j < N; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			swap(A[i], A[minj]);
			count++;
		}
	}

	return count;
}
