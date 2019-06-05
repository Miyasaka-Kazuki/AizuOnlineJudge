#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int INFTY = 1 << 30;

class Edge {
public:
	int outVal, weight;
	Edge(int o, int w): outVal(o), weight(w){}
};

void BFS(int start, vector<Edge> verVal[], int distance[], int verNum) {

	for (int i = 0; i < verNum; i++) distance[i] = INFTY;
	queue<int> que;
	que.push(start);
	distance[start] = 0;

	while (!que.empty()) {
		int nowVerVal = que.front();
		que.pop();
		for (int i = 0; i < verVal[nowVerVal].size(); i++) {
			Edge nowE = verVal[nowVerVal][i];
			if (distance[nowE.outVal] != INFTY) continue;

			distance[nowE.outVal] = distance[nowVerVal] + nowE.weight;
			que.push(nowE.outVal);
		}
	}
}

void DiameterOfATree(vector<Edge> verVal[], int distance[], int verNum) {

	int target = 0;
	int maxDis = 0;

	for (int i = 0; i < 2; i++) {
		BFS(target, verVal, distance, verNum);

		maxDis = 0;
		for (int i = 0; i < verNum; i++) {
			if (distance[i] == INFTY) continue;
			if (maxDis < distance[i]) {
				maxDis = distance[i];
				target = i;
			}
		}
	}

	cout << maxDis << endl;
}

int main() {

	vector<Edge> verVal[100000];
	int distance[100000];
	int verNum;
	cin >> verNum;

	for (int i = 0; i < verNum-1; i++) {
		int first, second, weight;
		cin >> first >> second >> weight;

		verVal[first].push_back(Edge(second, weight));
		verVal[second].push_back(Edge(first, weight));
	}

	DiameterOfATree(verVal, distance, verNum);

	return 0;
}