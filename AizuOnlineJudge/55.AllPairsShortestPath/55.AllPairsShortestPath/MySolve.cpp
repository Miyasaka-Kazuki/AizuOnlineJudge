#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
using namespace std;

//最短経路を入れるので最大で19億を超える可能性があるから
static const int INFTY = 2000000000;

void WarshallFloyd(int weight[][100], int verNum) {

	//kが増えるほど、使う頂点数を増やして最短経路を求める
	//つまり、動的計画法
	for (int k = 0; k < verNum; k++)
		for (int i = 0; i < verNum; i++) {
			//辺がつながっていないので更新するはずがないから
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

	//クエリ
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