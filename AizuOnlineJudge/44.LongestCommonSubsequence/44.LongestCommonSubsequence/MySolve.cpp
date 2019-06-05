#include <iostream>
#include <string>
using namespace std;
/*   Y\X  0 1  2 3 4 
             - -  -  -  -
        0	|0 0 0 0 0
        1	|0 0 1  1 1
        2	|0 0 1  2 2
        3	|0 1 2  2 4
        4	|0 1 2  2 4<= LCS
*/
int longestCommonSubsequence(string X, string Y) {
	int DP_memory[1000+1][1000+1]; //0~length文字
	int sizeX = X.length(); //0文字目を追加するためサイズがずれるので、
	int sizeY = Y.length(); //先に避難させておく
	X = " " + X;
	Y = " " + Y;
	for (int i = 0; i <= sizeX; i++)
		DP_memory[i][0] = 0;
	for (int i = 0; i <= sizeY; i++)
		DP_memory[0][i] = 0;

	for (int i = 1; i <= sizeX; i++) {
		for (int j = 1; j <= sizeY; j++) {
			if (X[i] == Y[j])
				DP_memory[i][j] = DP_memory[i - 1][j - 1] + 1;
			else if (DP_memory[i - 1][j] >= DP_memory[i][j - 1])
				DP_memory[i][j] = DP_memory[i - 1][j];
			else
				DP_memory[i][j] = DP_memory[i][j - 1];
		}
	}
	return DP_memory[sizeX][sizeY];
}

int main() {
	string lcsX[1000];
	string lcsY[1000];
	int setNum;

	cin >> setNum;
	for (int i = 0; i < setNum; i++) {
		cin >> lcsX[i];
		cin >> lcsY[i];

		int lcs = longestCommonSubsequence(lcsX[i], lcsY[i]);
		cout << lcs << endl;
	}
	return 0;
}