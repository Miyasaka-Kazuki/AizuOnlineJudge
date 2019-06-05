#include<iostream>
using namespace std;

void trace(int A[], int N);
	void insertionSort(int A[], int N);

int main() {
	int N; //�v�f��
	int A[100]; //����z��

	//����
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	//�v�Z
	trace(A, N);
	insertionSort(A, N);

	return 0;
}

//�z��̗v�f�����Ԃɏo��
void trace(int A[], int N) {
	for (int i = 0; i < N; i++) {
		if (i > 0) { cout << " "; }
		cout << A[i];
	}
	cout << endl;
}

//�}���\�[�g�i�O�I���W���z��j
void insertionSort(int A[], int N) {
	int j, v;
	for (int i = 1; i < N; i++) {
		v = A[i];
		j = i - 1; //(move)
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		trace(A, N);
	}
}