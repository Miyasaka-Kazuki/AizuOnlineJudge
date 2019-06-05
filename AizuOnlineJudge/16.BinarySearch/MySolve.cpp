#include<iostream>
using namespace std;

bool binarySearch(int key, int S[], int n) {
	int head, tail;
	head = 0;
	tail = n;
	while (head < tail) {
		int tempKey = (tail + head)/2;
		if (S[tempKey] != key) {
			if (S[tempKey] > key) {
				tail = tempKey;
			}
			else {
				head = tempKey + 1;
			}
		}
		else {
			return true;
		}
	}
	return false;
}

int main() {
	int sum = 0;
	int n, q;
	int S[100000];
	int key;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> key;
		if (binarySearch(key, S, n)) sum++;
	}

	cout << sum << endl;
}