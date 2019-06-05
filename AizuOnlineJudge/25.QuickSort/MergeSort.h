#pragma once
#include<Grobal.h>
class Merge {
public:
	void mergeSort(Card A[], int left, int right) {
		if (left + 1 >= right) return;

		int mid = (left + right) / 2;
		mergeSort(A, left,  mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}

private:
	void merge(Card A[], int left, int mid, int right) {
		int numL = mid - left;
		int numR = right - mid;

		//下でAの配列を更新するので半分ずつ別の配列に退避させておく
		//番犬も入れるため＋１する
		Card L[kMaxLeft];
		Card R[kMaxRight];
		for (int i = 0; i < numL; i++) {
			L[i] = A[left + i];
		}
		for (int i = 0; i < numR; i++) {
			R[i] = A[mid + i];
		}
		//比較するときに入れないためありえない値を入れる
		L[numL].iNumber = kImpossibleValue;
		R[numR].iNumber = kImpossibleValue;
		int iL = 0;
		int iR = 0;
		for (int j = left; j < right; j++) {
			if (L[iL].iNumber <= R[iR].iNumber) {
				A[j] = L[iL];
				iL++;
			}
			else {
				A[j] = R[iR];
				iR++;
			}
		}
	}

	static const int kMaxLeft = 50001;
	static const int kMaxRight = 50001;
	static const int kImpossibleValue = 1000000001;
};
