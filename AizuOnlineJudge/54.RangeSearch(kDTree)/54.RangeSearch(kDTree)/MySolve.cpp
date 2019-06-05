#include<iostream>
#include<algorithm>
#include <vector>
#include <cstdio>
using namespace std;

static const int NIL = -1;
int nodePointer;

class Node{
public:

	int valSubScript;
	int parent, left, right;
};

class Point {
public:

	Point(){}
	Point(int X, int Y, int ID): x(X), y(Y), id(ID){}

	void Print() {
//		cout << id << endl;
		printf("%d\n", id);
	}

	//‚±‚ê‚ª‚È‚¢‚ÆSTL‚ÌŒ^‚Éstruct‚ð“ü‚ê‚ç‚ê‚È‚¢
	bool operator <(const Point &p) {
		return id < p.id;
	}

	int GetX() const { return x; }
	int GetY() const { return y; }

private:

	int id;
	int x, y;
};

 bool LessX(const Point &p1, const Point &p2) {
	return p1.GetX() < p2.GetX();
}

 bool LessY(const Point &p1, const Point &p2) {
	return p1.GetY() < p2.GetY();
}

int makeKDTree(int left, int right, int depth, Point point[], Node kDNode[]) {

	if (left >= right) return NIL;

	int mid = (left + right) / 2;

	int curNP = nodePointer;
	nodePointer++;

	if (depth % 2 == 0) sort(point + left, point + right, LessX);
	else                         sort(point + left, point + right, LessY);

	kDNode[curNP].valSubScript = mid;
	kDNode[curNP].left = makeKDTree(left, mid, depth + 1, point, kDNode);
	kDNode[curNP].right = makeKDTree(mid + 1, right, depth + 1, point, kDNode);

	return curNP;
}

void FindVerticalPoint(int subScript, int minX, int maxX, int minY, int maxY, 
	int depth, vector<Point> &ans, Point point[], Node kDNode[]) {

	int x = point[kDNode[subScript].valSubScript].GetX();
	int y = point[kDNode[subScript].valSubScript].GetY();

	if (minX <= x && x <= maxX && minY <= y && y <= maxY)
		ans.push_back(point[kDNode[subScript].valSubScript]);

	if (depth % 2 == 0) {
		if (kDNode[subScript].left != NIL)
			if (minX <= x) FindVerticalPoint(kDNode[subScript].left, minX, maxX, minY, maxY, depth + 1, ans, point, kDNode);
		if (kDNode[subScript].right != NIL)
			if (x <= maxX) FindVerticalPoint(kDNode[subScript].right, minX, maxX, minY, maxY, depth + 1, ans, point, kDNode);
	} else {
		if (kDNode[subScript].left != NIL)
			if (minY <= y) FindVerticalPoint(kDNode[subScript].left, minX, maxX, minY, maxY, depth + 1, ans, point, kDNode);
		if (kDNode[subScript].right != NIL)
			if (y <= maxY) FindVerticalPoint(kDNode[subScript].right, minX, maxX, minY, maxY, depth + 1, ans, point, kDNode);
	}
}

int main() {
	int verNum;
	Point point[500000];
	Node kDNode[500000];

//	cin >> verNum;
	scanf("%d", &verNum);
	for (int i = 0; i < verNum; i++) {
		int x, y;
//		cin >> x >> y;
		scanf("%d %d", &x, &y);
		point[i] = Point(x, y, i);
		kDNode[i].left = kDNode[i].right = 
			kDNode[i].parent = NIL;
	}

	nodePointer = 0;
	int root = makeKDTree(0, verNum, 0, point, kDNode);

	int query;
	int minX, minY, maxX, maxY;
	//cin >> query;
	scanf("%d", &query);
	vector<Point> ans;
	for (int i = 0; i < query; i++) {
//		Point ans[500000];
		ans.clear();
//		cin >> minX >> maxX >> minY >> maxY;
		scanf("%d %d %d %d", &minX, &maxX, &minY, &maxY);
		FindVerticalPoint(root, minX, maxX, minY, maxY, 0, ans, point, kDNode);
		sort(ans.begin(), ans.end());
		for (int j = 0; j < ans.size(); j++) {
			ans[j].Print();
		}
//		cout << endl;
		printf("\n");
	}
}