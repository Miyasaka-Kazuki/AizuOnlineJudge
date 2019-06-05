#include <iostream>
using namespace std;

int MCM(int molCol[], int matNum) {
	int DP_memory[100+1][100+1];

	//使うのは１から
	for (int i = 1; i <= matNum; i++)
		DP_memory[i][i] = 0;

	for (int l = 2; l <= matNum; l++) { //調べる全体の範囲(i = 2なら2つの行列でそれぞれ最小の積を求める)
		for (int i = 1; i <= matNum - l + 1; i++) { //調べる範囲で最小の値
			int j = i + l - 1; //調べる値で最大の値
			DP_memory[i][j] = (1 << 30); //ありえないくらい大きい値(最小の値を求めるため)
			for (int k = i; k < j; k++) //iとjの間で積をするために区切る場所
				DP_memory[i][j] = DP_memory[i][j] < (DP_memory[i][k] + DP_memory[k + 1][j] + molCol[i - 1] * molCol[k] * molCol[j])
					? DP_memory[i][j] : (DP_memory[i][k] + DP_memory[k + 1][j] + molCol[i - 1] * molCol[k] * molCol[j]);
		}
	}

	return DP_memory[1][matNum];
}

int main() {
	//int matNum;
	//int molCol[200+1];
	//cin >> matNum;
	//for (int i = 1; i <= matNum; i++) {
	//	cin >> molCol[i - 1] >> molCol[i];
	//}

	//int answer = MCM(molCol, matNum);

	//cout << answer << endl;

	cout << (1 << 30) << endl << 
		(1 << 31) << endl << 
		(1 << 32) << endl;
	int j = 1;
	for (int i = 0; i < 30; i++) {
		j *= 2;
	}
	cout << j << endl;
	return 0;
}