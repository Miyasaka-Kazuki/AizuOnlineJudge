#include<iostream>
using namespace std;

bool solve(int A[], int n, int i, int key) {
	if (key == 0) return true;
	if (i >= n) return false;
	return solve(A, n, i + 1, key) || solve(A, n, i + 1, key - A[i]);
}

int main() {
	int n;
	int q;
	int A[20];

	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	cin >> q;
	
	for (int i = 0; i < q; i++) {
		int key;
		cin >> key;
		if (solve(A, n, 0, key)) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}