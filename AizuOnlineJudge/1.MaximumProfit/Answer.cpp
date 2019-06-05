#include<iostream>
//#include <algorithm>
using namespace std;

static const int MAX = 200000;

int main() {
	int R[MAX]; //価格の配列
	int n; //時刻数
	
	//入力
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> R[i];
	}

	//計算
	int maxv = -2000000000; //十分小さい値を初期値に設定
	int minv = R[0];

	for (int i = 1; i < n; i++) {
		maxv = max(maxv, R[i] - minv);
		minv = min(minv, R[i]);
	}

	//出力
	cout << maxv << endl;

	return 0;
}

int max(int oldMax, int newMax) {
	int nowMax;

	nowMax = oldMax;
	if (newMax > oldMax) {
		nowMax = newMax;
	}

	return nowMax;
}

int min(int oldMin, int newMin) {
	int nowMin;

	nowMin = oldMin;
	if (newMin > oldMin) {
		nowMin = newMin;
	}

	return nowMin;
}