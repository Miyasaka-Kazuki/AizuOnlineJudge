#include<iostream>
using namespace std;

int bubbleSort(int A[], int N);

int main() {
	int A[100]; //����z��
	int N; //�v�f��
	int sw; //�X���b�v�񐔁i��̗����j

	//����
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	//�v�Z
	sw = bubbleSort(A, N);

	//�o��
	for (int i = 0; i < N; i++) {
		if (i) { cout << " "; }
		cout << A[i];
	}
	cout << endl;
	cout << sw << endl;

	return 0;
}

//flag��p�����o�u���\�[�g
int bubbleSort(int A[], int N) {
	int sw = 0;
	bool flag = true;
	for (int i = 0; flag; i++) {
		flag = false;
		for (int j = N - 1; j > i; j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j-1]);
				flag = true;
				sw++;
			}
		}
	}
	return sw;
}
