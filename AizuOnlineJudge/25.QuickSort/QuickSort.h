#pragma once
#include<Grobal.h>

//�N�C�b�N�\�[�g�̋@�\��L���Ă���N���X
class Quick {
public:
	void QuickSort(Card caCard[], int iFirst, int iLast) {
		if (iFirst >= iLast) return;

		//�傫���̂Ə������̂ɕ����Ă��ꂼ��ċA
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
			iMinLast++; //iKey��菬�������̂������邩��
			swapCard(caCard, iMinLast, i);
		}

		//iKey�ɂ��Ă����̂�傫���̂Ə������̂̊ԂɎ����Ă���
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