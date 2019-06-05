#include<iostream>
using namespace std;

static const int kiMaxSize = 2000000;
static const int kiMaxValue = 10000;

//第一引数の配列をソートして第２引数に入れる関数
void CountingSort(const int aiArray[], int aiSortedArray[], const int iNumA) {
	int aiValCouArray[kiMaxValue] = { 0 };

	//aiValCouArrayにaiArrayの要素の出現数をカウントして記録する
	for (int i = 0; i < iNumA; i++) 
		aiValCouArray[aiArray[i]]++;

	//aiValCouArrayにaiArrayの要素以下の出現数をカウントして記録する
	for (int i = 1; i < kiMaxValue; i++)
		aiValCouArray[i] += aiValCouArray[i - 1];

	for (int i = iNumA-1; i >= 0; i--) {
		int iValue_count = aiValCouArray[aiArray[i]];
		//出現数１(ソートされた後,一番前にくるもの)がaiSortedArray[1]に入ってしまうため
		aiSortedArray[iValue_count-1] = aiArray[i];
		aiValCouArray[aiArray[i]]--;
	}
}

//入力された数列をO(n+k(数列の最大要素))でソートして出力する関数
int main() {
	int aiArray[kiMaxSize];
	int iNumA;
	
	//入力
	cin >> iNumA;
	for (int i = 0; i < iNumA; i++) cin >> aiArray[i];


	int aiSortedArray[kiMaxSize];
	CountingSort(aiArray, aiSortedArray, iNumA);


	//出力
	for (int i = 0; i < iNumA; i++) {
		if (i) cout << " ";
		cout << aiSortedArray[i];
	}
	cout << endl;

	return 0;
}