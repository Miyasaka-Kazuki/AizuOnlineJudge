#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
using namespace std;

//�ŒZ�o�H������̂ōő��19���𒴂���\�������邩��
static const int INFTY = 2000000000;

void WarshallFloyd(int weight[][100], int verNum) {

	//k��������قǁA�g�����_���𑝂₵�čŒZ�o�H�����߂�
	//�܂�A���I�v��@
	for (int k = 0; k < verNum; k++)
		for (int i = 0; i < verNum; i++) {
			//�ӂ��Ȃ����Ă��Ȃ��̂ōX�V����͂����Ȃ�����
			if (weight[i][k] == INFTY) continue;
			for (int j = 0; j < verNum; j++) {
				if (weight[k][j] == INFTY) continue;
				weight[i][j] = min(weight[i][j], weight[i][k] + weight[k][j]);
			}
		}
}

int main() {

	int weight[100][100];
	int verNum;
	int edgeNum;
	cin >> verNum >> edgeNum;

	//Initialize
	for (int i = 0; i < verNum; i++)
		for (int j = 0; j < verNum; j++)
			weight[i][j] = (i == j) ? 0 : INFTY;

	for (int i = 0; i < edgeNum; i++) {
		int first_ver, second_ver, wei;
		cin >> first_ver >> second_ver >> wei;
		weight[first_ver][second_ver] = wei;
	}

	WarshallFloyd(weight, verNum);

	//�N�G��
	bool negative = false;
	for (int i = 0; i < verNum; i++)
		if (weight[i][i] < 0) negative = true;

	if (negative)
		cout << "NEGATIVE CYCLE" << endl;
	else {
		for (int i = 0; i < verNum; i++) {
			for (int j = 0; j < verNum; j++) {
				if (j) cout << " ";

				string verVal;
				if (weight[i][j] == INFTY) verVal = "INF";
				else                                  verVal = to_string(weight[i][j]);

				cout << verVal;
			}
			cout << endl;
		}
	}

	return 0;
}