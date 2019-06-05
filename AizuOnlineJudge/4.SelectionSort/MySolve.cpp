#include<iostream>
using namespace std;

int selectionSort(int A[], int N);

int main() {
	int A[100]; //����z��
	int N; //����z��̒���

	//����
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	//�v�Z
	int count; //������
	count = selectionSort(A, N);

	//�o��
	for (int i = 0; i < N; i++) {
		if (i) { cout << " "; }
		cout << A[i];
	}
	cout << endl;
	cout << count << endl;
	return 0;
}

//�O�I���W���z���p���������ɕ��ёւ���I���\�[�g
int selectionSort(int A[], int N) {
	int count = 0;
	for (int i = 0; i < N - 1; i++) {
		int minj = i;
		for (int j = i + 1; j < N; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			swap(A[i], A[minj]);
			count++;
		}
	}

	return count;
}
