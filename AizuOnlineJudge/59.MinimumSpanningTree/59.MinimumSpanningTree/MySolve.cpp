#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Edge {
public:
	Edge(int source, int target, int cost) :
		firstVec(source), secondVec(target), weight(cost) {};

	int GetFirstVec() { return firstVec; }
	int GetSecondVec() { return secondVec; }
	int GetWeight() const{ return weight; }

	bool operator < (const Edge &e) const{
		return weight < e.GetWeight();
	}

private:
	int firstVec, secondVec, weight;
};

enum Query {
	Unit,
	Same,
};

class DisjointSet {
public:
	DisjointSet(int size) {
		rank.resize(size, 0);
		parent.resize(size, 0);
		for (int i = 0; i < size; i++) {
			MakeSet(i);
		}
	}

	bool Same(int x, int y) {
		return FindSet(x) == FindSet(y);
	}

	void Unit(int x, int y) {
		Link(FindSet(x), FindSet(y));
	}

private:
	void Link(int x, int y) {
		if (rank[x] > rank[y])
			parent[y] = x;
		else {
			parent[x] = y;
			if (rank[x] == rank[y])
				rank[y]++;
		}
	}

	//集合を新たに作る
	//集合の親を自分自身にしてるのはFindSetを作りやすくするため
	//(集合の親がreturnするときに、渡すのは自分自身でなければいけないが、
	//それ以外が返すのは親でなければいけないから)
	void MakeSet(int x) {
		parent[x] = x;
		rank[x] = 0;
	}

	//集合の親を返す
	//経路圧縮するために再帰を使う（詳細はp320）
	int FindSet(int x) {
		if (x != parent[x])
			parent[x] = FindSet(parent[x]);
		return parent[x];
	}

	vector<int> rank;
	vector<int> parent;
};

int Kruskal(vector<Edge> &edges, int vecNum) {

	sort(edges.begin(), edges.end());
	DisjointSet disSet = DisjointSet(vecNum+1);

	int firstVec, secondVec;
	int totalWeight = 0;
	for (int i = 0; i < edges.size(); i++) {

		Edge e = edges[i];
		if (!disSet.Same(e.GetFirstVec(), e.GetSecondVec())) {
			disSet.Unit(e.GetFirstVec(), e.GetSecondVec());
			totalWeight += e.GetWeight();
		}
	}

	return totalWeight;
}

int main() {

	int vecNum;
	int edgeNum;
	vector<Edge> edges;

	cin >> vecNum >> edgeNum;
	for (int i = 0; i < edgeNum; i++) {
		int firstVec, secondVec, weight;
		cin >> firstVec >> secondVec >> weight;
		edges.push_back(Edge(firstVec, secondVec, weight));
	}

	int weightNum = Kruskal(edges, vecNum);
	cout << weightNum << endl;

	return 0;
}