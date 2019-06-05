#include<iostream>
using namespace std;

int selectionSort(int A[], int N);

int main() {
	int A[100]; //”—ñ”z—ñ
	int N; //’·‚³

	//“ü—Í
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	//ŒvZ
	int swCount; //ŒğŠ·‰ñ”
	swCount = selectionSort(A, N);

	//o—Í
	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << swCount << endl;
}

int selectionSort(int A[], int N) {
	int swCount = 0;
	for (int i = 0; i < N-1; i++) {
		int minj = i;
		for (int j = i + 1; j < N; j++) {
			if (A[j] < A[minj]) minj = j;
		}
		swap(A[i], A[minj]);
		if (i != minj) swCount++;
	}

	return swCount;
}
