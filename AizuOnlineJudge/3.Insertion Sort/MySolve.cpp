#include<iostream>
using namespace std;

static const int A_MAX = 100;

int main() {
	int N; //数列の長さ
	int A[A_MAX]; //数列配列

	//入力
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}


	//計算
	for (int i = 1; i < N; i++) {
		//仮出力
		for (int j = 0; j < N-1; j++) {
			cout << A[j] << " ";
		}
		cout << A[N-1] << endl;

		int temp = A[i]; //ソートされてない数列の最前列の値
		int j = i - 1; //ソートされた数列の最後尾（動かす）
		
		//ソート
		while (j >= 0 && A[j] > temp) {
			A[j + 1] = A[j]; //後ろにずらす
			j--;
		}
		//j--してるので＋１して元に戻す
		A[j + 1] = temp;
	}

	//出力
	for (int j = 0; j < N - 1; j++) {
		cout << A[j] << " ";
	}
	cout << A[N - 1] << endl;

	return 0;
}