#pragma once
#include<Grobal.h>

//クイックソートの機能を有しているクラス
class Quick {
public:
	void QuickSort(Card caCard[], int iFirst, int iLast) {
		if (iFirst >= iLast) return;

		//大きいのと小さいのに分けてそれぞれ再帰
		int iBorder = Partition(caCard, iFirst, iLast);
		QuickSort(caCard, iFirst, iBorder - 1);
		QuickSort(caCard, iBorder + 1, iLast);
	}

private:
	int Partition(Card caCard[], int iFirst, int iLast) {
		int iKey = caCard[iLast].iNumber;
		int iMinLast = iFirst - 1;

		for (int i = iFirst; i < iLast; i++) {
			if (caCard[i].iNumber > iKey) continue;
			iMinLast++; //iKeyより小さいものが増えるから
			swapCard(caCard, iMinLast, i);
		}

		//iKeyにしてたものを大きいのと小さいのの間に持ってくる
		iMinLast++;
		swapCard(caCard, iMinLast, iLast);
		return iMinLast;
	}

	void swapCard(Card caCard[], int  iA, int iB) {
		Card caTemp = caCard[iA];
		caCard[iA] = caCard[iB];
		caCard[iB] = caTemp;
	}
};