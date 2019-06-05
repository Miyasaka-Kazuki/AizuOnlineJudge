#include<iostream>
using namespace std;

int bubbleSort(int A[], int N, int count);

int main() {
	int N; //����̒���
	int A[100]; //����
	int count; //�\�[�g�̌�����
	count = 0;

	//����
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	//�v�Z
	count = bubbleSort(A, N, count);

	//�o��
	for (int i = 0; i < N; i++) {
		if (i > 0) { cout << " "; }
		cout << A[i];
	}
	cout << endl;
	cout << count << endl;

	return 0;
}

//�O�I���W���z���p�����o�u���\�[�g�֐�
int bubbleSort(int A[], int N, int count) {
	bool flag;
	flag = true;

	while (flag) {
		flag = false;
		for (int j = N - 1; j > 0; j--) {
			if (A[j-1] > A[j]) {
				flag = true;
				int temp = A[j - 1];
				A[j - 1] = A[j];
				A[j] = temp;

				count++;
			}
		}
	}

	return count;
}