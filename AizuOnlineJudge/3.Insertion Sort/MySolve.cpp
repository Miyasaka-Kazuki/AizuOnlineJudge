#include<iostream>
using namespace std;

static const int A_MAX = 100;

int main() {
	int N; //����̒���
	int A[A_MAX]; //����z��

	//����
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}


	//�v�Z
	for (int i = 1; i < N; i++) {
		//���o��
		for (int j = 0; j < N-1; j++) {
			cout << A[j] << " ";
		}
		cout << A[N-1] << endl;

		int temp = A[i]; //�\�[�g����ĂȂ�����̍őO��̒l
		int j = i - 1; //�\�[�g���ꂽ����̍Ō���i�������j
		
		//�\�[�g
		while (j >= 0 && A[j] > temp) {
			A[j + 1] = A[j]; //���ɂ��炷
			j--;
		}
		//j--���Ă�̂Ł{�P���Č��ɖ߂�
		A[j + 1] = temp;
	}

	//�o��
	for (int j = 0; j < N - 1; j++) {
		cout << A[j] << " ";
	}
	cout << A[N - 1] << endl;

	return 0;
}