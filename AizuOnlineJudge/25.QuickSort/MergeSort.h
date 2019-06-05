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

		//����A�̔z����X�V����̂Ŕ������ʂ̔z��ɑޔ������Ă���
		//�Ԍ�������邽�߁{�P����
		Card L[kMaxLeft];
		Card R[kMaxRight];
		for (int i = 0; i < numL; i++) {
			L[i] = A[left + i];
		}
		for (int i = 0; i < numR; i++) {
			R[i] = A[mid + i];
		}
		//��r����Ƃ��ɓ���Ȃ����߂��肦�Ȃ��l������
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
