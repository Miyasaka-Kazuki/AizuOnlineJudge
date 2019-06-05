#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int S[100000];
	int numS;

	cin >> numS;
	for (int i = 0; i < numS; i++) {
		cin >> S[i];
	}

	int numT;
	int sum = 0;
	cin >> numT;
	for (int i = 0; i < numT; i++) {
		int key;
		cin >> key;
		if (*lower_bound(S, S + numS, key) == key) sum++;
	}

	cout << sum << endl;

	return 0;
}