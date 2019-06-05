#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

#define MAX 10000

void BFS(vector<int> verVal[], vector<bool> &color, list<int> &sortVers, vector<int> &indeg, int subScript) {
	queue<int> bfsQ;
	bfsQ.push(subScript);
	color[subScript] = true;

	while (!bfsQ.empty()) {
		int curVerVal = bfsQ.front(); 
		bfsQ.pop();

		sortVers.push_back(curVerVal);

		for (int i = 0; i < verVal[curVerVal].size(); i++) {
			int outVerVal = verVal[curVerVal][i];
			indeg[outVerVal]--;
			if (indeg[outVerVal] == 0 && !color[outVerVal]) {
				color[outVerVal] = true;
				bfsQ.push(outVerVal);
			}
		}
	}
}

list<int> TopologicalSort(vector<int> verVal[], int verNum) {

	list<int> sortVers;
	vector<bool> color(verNum);
	vector<int> indeg(verNum);

	//Initialie
	for (int i = 0; i < color.size(); i++)
		color[i] = false;
	for (int i = 0; i < indeg.size(); i++)
		indeg[i] = 0;
	for (int first = 0; first < verNum; first++) {
		for (int second = 0; second < verVal[first].size(); second++) {
			int outVerVal = verVal[first][second];
			indeg[outVerVal]++;
		}
	}

	for (int i = 0; i < verNum; i++)
		if (indeg[i] == 0 && !color[i]) {
			BFS(verVal, color, sortVers, indeg, i);
		}

	return sortVers;
}

int main() {

	int verNum, edgeNum;
	cin >> verNum >> edgeNum;
	vector<int> verVal[MAX];

	for (int i = 0; i < edgeNum; i++) {
		int first, second;
		cin >> first >> second;
		verVal[first].push_back(second);
	}

    list<int> sortVers = TopologicalSort(verVal, verNum);

	for (list<int>::iterator it = sortVers.begin(); it != sortVers.end(); it++)
		cout << *it << endl;

	return 0;
}