#include<iostream>
using namespace std;

bool binarySearch(int key, int A[], int n) {
	int left = 0;
	int right = n;
	int middle;

	while (left < right) {
		int middle = (left + right) / 2;
		if (A[middle] == key) {
			return true;
		}
		else if (A[middle] < key) {
			left = middle + 1;
		}
		else {
			right = middle;
		}
	}
	return false;
}

int main() {
	int A[100000];
	int n;
	int q;
	int sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int key;
		cin >> key;
		if (binarySearch(key, A, n)) sum++;
	}

	cout << sum << endl;
	
	return 0;
}