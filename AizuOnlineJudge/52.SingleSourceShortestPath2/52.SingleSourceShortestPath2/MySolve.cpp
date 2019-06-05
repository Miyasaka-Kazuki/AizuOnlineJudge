#include<iostream>
#include <queue>
using namespace std;

#define INFTY (1 << 30)

//ノードの色
enum Color {
	WHITE,
	GRAY,
	BLACK,
};


//SSSP
void Dijkstra(vector<pair<int, int>> *v_w_m, int verNum) {

	//初期設定
	priority_queue<pair<int, int>> pQ;
	int distance[10000];
	Color color[10000];
	int parent[10000];
	for (int i = 0; i < verNum; i++) {
		color[i] = WHITE;
		distance[i] = INFTY;
		parent[i] = -1;
	}
	distance[0] = 0;
	pQ.push(make_pair(0, 0));


	//SSSP操作
	while (!pQ.empty()) {

		//グレイの中から重みが最小のノードを選ぶ
//		int min_cost = INFTY;
		int subScript;
		pair<int, int> wei_sub_map = pQ.top();
		pQ.pop();
		subScript = wei_sub_map.second;
		//for (int i = 0; i < verNum; i++) {
		//	if (color[i] != BLACK && distance[i] < min_cost) {
		//		min_cost = distance[i];
		//		subScript = i;
		//	}
		//}

		//ブラックにする
		color[subScript] = BLACK;

		//最短じゃなければ親が変わらないから何もしない
		//これがないと4169407Bのとき、0.01sec遅くなる
		if (distance[subScript] < wei_sub_map.first * -1)
			continue;

		//隣接をグレイに
		for (int i = 0; i < v_w_m[subScript].size(); i++) {
			int outV = v_w_m[subScript][i].first;
			if (color[outV] == BLACK) continue;
			if (distance[outV] < distance[subScript] + v_w_m[subScript][i].second) continue;

			distance[outV] = distance[subScript] + v_w_m[subScript][i].second;
			parent[outV] = subScript;
			color[outV] = GRAY;
			pQ.push(make_pair(distance[outV] * -1, outV));
		}
	}

	//列挙
	int weight_sum = 0;
	for (int i = 0; i < verNum; i++) {
		cout << i << " " << (distance[i] == INFTY ? -1 : distance[i]) << endl;
	}
}


int main() {

	int verNum;
//	int verValWeight[100][100];
	vector<pair<int, int>> v_w_m[10000];
	int parent[10000];

	//初期設定
//	v_w_m = new vector<pair<int, int>>();
	cin >> verNum;
	//for (int i = 0; i < verNum; i++)
	//	for (int j = 0; j < verNum; j++)
	//		verValWeight[i][j] = INFTY;

	//入力処理
	for (int i = 0; i < verNum; i++) {
		int verVal, outNum;
		cin >> verVal >> outNum;
		for (int j = 0; j < outNum; j++) {
			int outVerVal, weight;
			cin >> outVerVal >> weight;
//			v_w_m[verVal].push_back(make_pair(outVerVal, weight));
			v_w_m[verVal].push_back(make_pair(outVerVal, weight));
			//			verValWeight[i][outVerVal] = weight;
		}
	}

	//SSSP
	Dijkstra(v_w_m, verNum);

	return 0;
}