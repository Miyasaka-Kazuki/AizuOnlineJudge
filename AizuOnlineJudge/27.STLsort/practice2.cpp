#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int iaVec[5];
	int iNumVec = 5;

	//����
	for (int i = 0; i < iNumVec; i++) cin >> iaVec[i];

	stable_sort(iaVec, iaVec + iNumVec);

	//�o��
	for (int i = 0; i < iNumVec; i++) {
		cout << iaVec[i] << " ";
	}
	cout << endl;

	return 0;
}