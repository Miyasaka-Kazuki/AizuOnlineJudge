#include<iostream>
#include<string>
using namespace std;

#define NIL -1

class Node {
public:
	int iParent_;
	int iLeftChild_;
	int iRightBrother_;
	int iDepth_;
};

class Tree {
public:
	Tree(int iNum):iMaxNodeNum_(iNum){
		for (int i = 0; i < iNum; i++) {
			noNode_[i].iParent_            = NIL;
			noNode_[i].iLeftChild_       = NIL;
			noNode_[i].iRightBrother_ = NIL;
		}
	}

	int searchRootIndex() {
		for (int i = 0; i < iMaxNodeNum_; i++)
			if (noNode_[i].iParent_ == NIL) return i;
	}

	void setNodeValue() {
		for (int iCurNo_i = 0; iCurNo_i < iMaxNodeNum_; iCurNo_i++) {
			int iNo, iChiNum;
			int leftBrotherOfChild = NIL;
			cin >> iNo >> iChiNum;
			for (int iCurChi_i = 0; iCurChi_i < iChiNum; iCurChi_i++) {
				int iChi;
				cin >> iChi;
				//最初なら左の子に、それ以外は左の子の兄弟に
				if (iCurChi_i == 0) noNode_[iNo].iLeftChild_ = iChi;
				else {
					noNode_[leftBrotherOfChild].iRightBrother_ = iChi;
				}
				leftBrotherOfChild = iChi;
				noNode_[iChi].iParent_ = iNo;
			}
		}

		int iRoIn = searchRootIndex();
		setDepth(iRoIn, /*depth =*/0);
	}

	void setDepth(int iNum, int iDep) {
		noNode_[iNum].iDepth_ = iDep;
		if (noNode_[iNum].iRightBrother_ != NIL) 
			setDepth(noNode_[iNum].iRightBrother_, iDep);
		if (noNode_[iNum].iLeftChild_ != NIL)
			setDepth(noNode_[iNum].iLeftChild_, iDep+1);
	}

	void print() {
		for (int iNodeNum_i = 0; iNodeNum_i < iMaxNodeNum_; iNodeNum_i++) {
			//タイプの決定
			string type = "internal node";
			if (noNode_[iNodeNum_i].iParent_ == NIL) type = "root";
			else if (noNode_[iNodeNum_i].iLeftChild_ == NIL) type = "leaf";

			//出力
			cout << "node " << iNodeNum_i << ": ";
			cout << "parent = " << noNode_[iNodeNum_i].iParent_ << ", ";
			cout << "depth = " << noNode_[iNodeNum_i].iDepth_ << ", ";
			cout << type << ", ";
			cout << "[";
			Node currentNode = noNode_[iNodeNum_i];
			int i = 0;
			for (int iChildNodeNum_i = currentNode.iLeftChild_; iChildNodeNum_i != NIL;iChildNodeNum_i = noNode_[iChildNodeNum_i].iRightBrother_) {
				if (i++)  cout << ", ";
				cout << iChildNodeNum_i;
			}
			cout << "]" << endl;
		}
	}
private:
	static const int kMax_Node = 100000;
	Node noNode_[kMax_Node];
	int iMaxNodeNum_;
};

int main() {
	int iNodeNum;
	cin >> iNodeNum;

	//初期化：NULLを入れてる
	Tree trNodeTree(iNodeNum);
	
	//この中で入力される
	trNodeTree.setNodeValue();

	//出力
	trNodeTree.print();
	return 0;
}