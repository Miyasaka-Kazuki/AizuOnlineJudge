#include<iostream>
#include<MergeSort.h>
#include<QuickSort.h>
#include<Grobal.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

//二つのカードの並びが一致してたらtrueを返す関数
bool ReserchIsStable(Card caCard[], Card caCardSample[], int iCardNum) {
	for (int i = 0; i < iCardNum; i++) {
		if (caCard[i].cType == caCardSample[i].cType) continue;
		return false;
	}
	return true;
}

//カードの列を整列させるプログラム
int main() {
	Card caCard[kCaNum];
	Card caCardSample[kCaNum];
	int iCardNum;

	//入力
	cin >> iCardNum;
	for (int i = 0; i < iCardNum; i++) {
		int iN; char cT;
		cin >> cT; 
		cin >> iN;
		caCardSample[i].cType = caCard[i].cType = cT;
		caCardSample[i].iNumber = caCard[i].iNumber = iN;
	}
	
	//スコープがないほうが0.5秒くらい速かった...
	auto start = system_clock::now();
	for (int i = 0; i < 10000; i++ ) {
		{	//整列させるのにクイックソートを使う
			Quick quQuick;
			quQuick.QuickSort(caCard, /*iFirst = */0, /*iLast = */iCardNum - 1);
		}
		{//クイックソートが安定かどうか調べるためマージソートでも整列
			Merge meMerge;
			meMerge.mergeSort(caCardSample, /*iBegin = */0, /*iEnd = */iCardNum);
		}
	}
	auto end = system_clock::now();
	auto elapsed = end - start;
	auto sec = duration_cast<milliseconds>(elapsed).count();

	//出力
	//クイックソートが安定かどうか比較して調べる
	if (bool bIsStable = ReserchIsStable(caCard, caCardSample, iCardNum)) 
		cout << "Stable"        << endl;
	else	
		cout << "Not stable" << endl;
	for (int i = 0; i < iCardNum; i++) {
		cout << caCard[i].cType      << " " ;
		cout << caCard[i].iNumber << endl;
	}
	cout << sec << endl;

	return 0;
}