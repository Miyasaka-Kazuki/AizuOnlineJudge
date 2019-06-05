#include<iostream>
#include<MergeSort.h>
#include<QuickSort.h>
#include<Grobal.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

//��̃J�[�h�̕��т���v���Ă���true��Ԃ��֐�
bool ReserchIsStable(Card caCard[], Card caCardSample[], int iCardNum) {
	for (int i = 0; i < iCardNum; i++) {
		if (caCard[i].cType == caCardSample[i].cType) continue;
		return false;
	}
	return true;
}

//�J�[�h�̗�𐮗񂳂���v���O����
int main() {
	Card caCard[kCaNum];
	Card caCardSample[kCaNum];
	int iCardNum;

	//����
	cin >> iCardNum;
	for (int i = 0; i < iCardNum; i++) {
		int iN; char cT;
		cin >> cT; 
		cin >> iN;
		caCardSample[i].cType = caCard[i].cType = cT;
		caCardSample[i].iNumber = caCard[i].iNumber = iN;
	}
	
	//�X�R�[�v���Ȃ��ق���0.5�b���炢��������...
	auto start = system_clock::now();
	for (int i = 0; i < 10000; i++ ) {
		{	//���񂳂���̂ɃN�C�b�N�\�[�g���g��
			Quick quQuick;
			quQuick.QuickSort(caCard, /*iFirst = */0, /*iLast = */iCardNum - 1);
		}
		{//�N�C�b�N�\�[�g�����肩�ǂ������ׂ邽�߃}�[�W�\�[�g�ł�����
			Merge meMerge;
			meMerge.mergeSort(caCardSample, /*iBegin = */0, /*iEnd = */iCardNum);
		}
	}
	auto end = system_clock::now();
	auto elapsed = end - start;
	auto sec = duration_cast<milliseconds>(elapsed).count();

	//�o��
	//�N�C�b�N�\�[�g�����肩�ǂ�����r���Ē��ׂ�
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