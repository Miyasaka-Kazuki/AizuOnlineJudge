#include<iostream>
using namespace std;

#define INFTY (1 << 30)

//ノードの色
enum Color {
	WHITE,
	GRAY,
	BLACK,
};


//SSSP
void Dijkstra(int verValWeight[][100], int verNum) {

	//初期設定
	int distance[100];
	Color color[100];
	int parent[100];
	for (int i = 0; i < verNum; i++) {
		color[i] = WHITE;
		distance[i] = INFTY;
		parent[i] = -1;
	}
	distance[0] = 0;

	//SSSP操作
	while (true) {

		//グレイの中から重みが最小のノードを選ぶ
		int min_cost = INFTY;
		int subScript;
		for (int i = 0; i < verNum; i++) {
			if (color[i] != BLACK && distance[i] < min_cost) {
				min_cost = distance[i];
				subScript = i;
			}
		}

		//終了
		if (min_cost == INFTY)
			break;

		//ブラックにする
		color[subScript] = BLACK;

		//隣接をグレイに
		for (int i = 0; i < verNum; i++) {
			if (color[i] != BLACK && verValWeight[subScript][i] != INFTY) {
				if (distance[subScript] + verValWeight[subScript][i] < distance[i]) {
					distance[i] = distance[subScript] + verValWeight[subScript][i];
					parent[i] = subScript;
					color[i] = GRAY;
				}
			}
		}
	}

	//列挙
	int weight_sum = 0;
	for (int i = 0; i < verNum; i++) {
		cout << i << " " << distance[i] << endl;
	}
}


int main() {

	int verNum;
	int verValWeight[100][100];
	int parent[100];

	//初期設定
	cin >> verNum;
	for (int i = 0; i < verNum; i++)
		for (int j = 0; j < verNum; j++)
			verValWeight[i][j] = INFTY;

	//入力処理
	for (int i = 0; i < verNum; i++) {
		int verVal, outNum;
		cin >> verVal >> outNum;
		for (int j = 0; j < outNum; j++) {
			int outVerVal, weight;
			cin >> outVerVal >> weight;
			verValWeight[i][outVerVal] = weight;
		}
	}

	//SSSP
	Dijkstra(verValWeight, verNum);

	return 0;
}