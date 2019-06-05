#include<iostream>
#include<string>
using namespace std;

#define NIL -1

class Node {
public:
	int iParent_;
	int iLeftChild_;
	int iRightChild_;
	int iDepth_;
	int iHeight_;
};

class Tree {
public:
	Tree(int iNum) :iMaxNodeNum_(iNum) {
		for (int i = 0; i < iNum; i++) {
			noNode_[i].iParent_ = NIL;
			noNode_[i].iLeftChild_ = NIL;
			noNode_[i].iRightChild_ = NIL;
			noNode_[i].iHeight_ = NIL;
		}
	}

	int searchRootIndex() {
		for (int i = 0; i < iMaxNodeNum_; i++)
			if (noNode_[i].iParent_ == NIL) return i;
	}

	void setNodeValue() {
		for (int iCurNo_i = 0; iCurNo_i < iMaxNodeNum_; iCurNo_i++) {
			int iNo, iChiL, iChiR;
			cin >> iNo >> iChiL >> iChiR;
			noNode_[iNo].iLeftChild_ = iChiL;
			noNode_[iNo].iRightChild_ = iChiR;

			noNode_[iChiL].iParent_ = iNo;
			noNode_[iChiR].iParent_ = iNo;
		}

		int iRoInx = searchRootIndex();
		setDepth(iRoInx, /*depth =*/0);
		setHeight(iRoInx,/*depth =*/0);
	}

	void setDepth(int iNum, int iDep) {
		noNode_[iNum].iDepth_ = iDep;
		if (noNode_[iNum].iRightChild_ != NIL)
			setDepth(noNode_[iNum].iRightChild_, iDep + 1);
		if (noNode_[iNum].iLeftChild_ != NIL)
			setDepth(noNode_[iNum].iLeftChild_, iDep + 1);
	}

	int setHeight(int iNum, int iHeight) {
		int iLH = 0, iRH = 0;
		if (noNode_[iNum].iRightChild_ != NIL)
			iRH = setHeight(noNode_[iNum].iRightChild_, iHeight) + 1;
		if (noNode_[iNum].iLeftChild_ != NIL)
			iLH = setHeight(noNode_[iNum].iLeftChild_, iHeight) + 1;

		noNode_[iNum].iHeight_ = iRH > iLH ? iRH : iLH;
		return noNode_[iNum].iHeight_;
	}

	void print() {
		int iRoId = searchRootIndex();
		cout << "Preorder" << endl;
		printWidthPreorder(iRoId);
		cout << endl;
		cout << "Inorder" << endl;
		printWidthInorder(iRoId);
		cout << endl;
		cout << "Postorder" << endl;
		printWidthPostorder(iRoId);
		cout << endl;
	}
	void printWidthPreorder(int iNodeId) {
		if (iNodeId == NIL) return;
		cout << " " << iNodeId;
		printWidthPreorder(noNode_[iNodeId].iLeftChild_);
		printWidthPreorder(noNode_[iNodeId].iRightChild_);
	}
	void printWidthInorder(int iNodeId) {
		if (iNodeId == NIL) return;
		printWidthInorder(noNode_[iNodeId].iLeftChild_);
		cout << " " << iNodeId;
		printWidthInorder(noNode_[iNodeId].iRightChild_);
	}
	void printWidthPostorder(int iNodeId) {
		if (iNodeId == NIL) return;
		printWidthPostorder(noNode_[iNodeId].iLeftChild_);
		printWidthPostorder(noNode_[iNodeId].iRightChild_);
		cout << " " << iNodeId;
	}
private:
	string getType(Node iCurN) {
		if (iCurN.iParent_ == NIL) return "root";
		else if (iCurN.iLeftChild_ == NIL && iCurN.iRightChild_ == NIL) return "leaf";
		return "internal node";
	}

	int getSiblingNum(Node iCurN, int iCurNodeNum) {
		if (iCurN.iParent_ == NIL) return -1;
		int iSiblingNodeNum = -1;
		Node iParNode = noNode_[iCurN.iParent_]; //à–¾•Ï”
												 //©•ª‚¶‚á‚È‚­‚ÄNIL‚¶‚á‚È‚¢‚à‚Ì‚ª‘¶İ‚·‚é‚È‚ç
		if (iParNode.iLeftChild_ != iCurNodeNum && iParNode.iLeftChild_ != NIL) iSiblingNodeNum = iParNode.iLeftChild_;
		else if (iParNode.iRightChild_ != iCurNodeNum && iParNode.iRightChild_ != NIL) iSiblingNodeNum = iParNode.iRightChild_;
		return iSiblingNodeNum;
	}

	int getChildNum(Node iCurN) {
		int iChildNum = 0;
		if (iCurN.iLeftChild_ != NIL) iChildNum++;
		if (iCurN.iRightChild_ != NIL) iChildNum++;
		return iChildNum;
	}

	static const int kMax_Node = 25;
	Node noNode_[kMax_Node];
	int iMaxNodeNum_;
};

int main() {
	int iNodeNum;
	cin >> iNodeNum;

	//‰Šú‰»FNULL‚ğ“ü‚ê‚Ä‚é
	Tree trNodeTree(iNodeNum);

	//‚±‚Ì’†‚Å“ü—Í‚³‚ê‚é
	trNodeTree.setNodeValue();

	//o—Í
	trNodeTree.print();
	return 0;
}