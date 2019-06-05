#include<iostream>
using namespace std;

static const int kiMaxSize = 2000000;
static const int kiMaxValue = 10000;

//�������̔z����\�[�g���đ�Q�����ɓ����֐�
void CountingSort(const int aiArray[], int aiSortedArray[], const int iNumA) {
	int aiValCouArray[kiMaxValue] = { 0 };

	//aiValCouArray��aiArray�̗v�f�̏o�������J�E���g���ċL�^����
	for (int i = 0; i < iNumA; i++) 
		aiValCouArray[aiArray[i]]++;

	//aiValCouArray��aiArray�̗v�f�ȉ��̏o�������J�E���g���ċL�^����
	for (int i = 1; i < kiMaxValue; i++)
		aiValCouArray[i] += aiValCouArray[i - 1];

	for (int i = iNumA-1; i >= 0; i--) {
		int iValue_count = aiValCouArray[aiArray[i]];
		//�o�����P(�\�[�g���ꂽ��,��ԑO�ɂ������)��aiSortedArray[1]�ɓ����Ă��܂�����
		aiSortedArray[iValue_count-1] = aiArray[i];
		aiValCouArray[aiArray[i]]--;
	}
}

//���͂��ꂽ�����O(n+k(����̍ő�v�f))�Ń\�[�g���ďo�͂���֐�
int main() {
	int aiArray[kiMaxSize];
	int iNumA;
	
	//����
	cin >> iNumA;
	for (int i = 0; i < iNumA; i++) cin >> aiArray[i];


	int aiSortedArray[kiMaxSize];
	CountingSort(aiArray, aiSortedArray, iNumA);


	//�o��
	for (int i = 0; i < iNumA; i++) {
		if (i) cout << " ";
		cout << aiSortedArray[i];
	}
	cout << endl;

	return 0;
}