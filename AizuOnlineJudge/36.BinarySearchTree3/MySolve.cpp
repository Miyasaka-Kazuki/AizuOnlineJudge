#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

struct Node {
	int iKey_;
	Node *pParent_;
	Node *pLeftChild_;
	Node *pRightChild_;
};

class Tree {
public:
	Tree(int iNum) :iMaxNodeNum_(iNum), iCurNodeNum_(0) {}

	void setNodeValue() {
		for (int iCurNode_i = 0; iCurNode_i < iMaxNodeNum_; iCurNode_i++) {
			string sCommand;
			cin >> sCommand;
			if (sCommand[0] == 'i') {
				int iKey;
				cin >> iKey;
				insertNode(iKey);
			}
			else if (sCommand[0] == 'f') {
				int iKey;
				cin >> iKey;
				Node* findNode = isNode(iKey);
				if (findNode) cout << "yes" << endl;
				else			cout << "no" << endl;
			}
			else if (sCommand[0] == 'd')  {
				int iKey;
				cin >> iKey;
				deleteNode(iKey);
			}
			else {
				print();
			}
		}
	}

private:
	// sCommand = insert
	void insertNode(int iKey) {
		Node *pNewNode = new Node;
		//èâä˙íiäK
		pNewNode->iKey_ = iKey;
		pNewNode->pParent_ = NULL;
		pNewNode->pLeftChild_ = NULL;
		pNewNode->pRightChild_ = NULL;
		iCurNodeNum_++;
		if (iCurNodeNum_ == 1) { //àÍî‘ç≈èâÇÃÉmÅ[ÉhÇ»ÇÁ
			pRoot_ = pNewNode;
			return;
		}

		searchNewNodeLocation(pNewNode);
	}
	void searchNewNodeLocation(Node *pNewNode) {
		Node *pCurNode = pRoot_;
		Node *pCurParentNode = NULL;
		while (pCurNode != NULL) {
			pCurParentNode = pCurNode;
			if (pNewNode->iKey_ < pCurNode->iKey_) pCurNode = pCurNode->pLeftChild_;
			else                                   pCurNode = pCurNode->pRightChild_;
		}
		pNewNode->pParent_ = pCurParentNode;

		if (pNewNode->iKey_ < pCurParentNode->iKey_) pCurParentNode->pLeftChild_ = pNewNode;
		else                                   pCurParentNode->pRightChild_ = pNewNode;
	}

	//sCommand = find
	Node* isNode(int iKey) {
		Node *curNode = pRoot_;
		while (curNode != NULL) {
			if (curNode->iKey_ == iKey) return curNode;
			if (iKey < curNode->iKey_) {
				curNode = curNode->pLeftChild_;
			}
			else {
				curNode = curNode->pRightChild_;
			}
		}
		return NULL;
	}

	// sCommand = delete
	void deleteNode(int iKey) {
		Node* wantToDelete_node = isNode(iKey);
		if (wantToDelete_node == NULL) return;
		Node* actuallyDelete_node;
		Node* actuallyDeleteNode_child;
		
		if (wantToDelete_node->pLeftChild_  == NULL ||
			wantToDelete_node->pRightChild_ == NULL)  actuallyDelete_node = wantToDelete_node;
		else										  actuallyDelete_node = conputeNextNodeInOrder(wantToDelete_node);

		if (actuallyDelete_node->pLeftChild_ != NULL) actuallyDeleteNode_child = actuallyDelete_node->pLeftChild_;
		else										  actuallyDeleteNode_child = actuallyDelete_node->pRightChild_;

		if (actuallyDeleteNode_child != NULL)		  actuallyDeleteNode_child->pParent_ = actuallyDelete_node->pParent_;

		if (actuallyDelete_node->pParent_ == NULL) pRoot_ = actuallyDeleteNode_child;
		else {
			Node* parent = actuallyDelete_node->pParent_;
			if (actuallyDelete_node == parent->pLeftChild_) parent->pLeftChild_  = actuallyDeleteNode_child;
			else											parent->pRightChild_ = actuallyDeleteNode_child;
		}

		if (actuallyDelete_node != wantToDelete_node) wantToDelete_node->iKey_ = actuallyDelete_node->iKey_;

		delete actuallyDelete_node;
	}
	Node* conputeNextNodeInOrder(Node* wantNode) {
		assert(wantNode->pRightChild_ != NULL);
		Node* child_node = wantNode->pRightChild_;
		while (child_node->pLeftChild_ != NULL) {
			child_node = child_node->pLeftChild_;
		}
		return child_node;
	}

	// sCommand = print
	void print() {
		printWidthInorder(pRoot_);
		cout << endl;
		printWidthPreorder(pRoot_);
		cout << endl;
	}
	void printWidthPreorder(Node *pN) {
		if (pN == NULL) return;
		cout << " " << pN->iKey_;
		printWidthPreorder(pN->pLeftChild_);
		printWidthPreorder(pN->pRightChild_);
	}
	void printWidthInorder(Node *pN) {
		if (pN == NULL) return;
		printWidthInorder(pN->pLeftChild_);
		cout << " " << pN->iKey_;
		printWidthInorder(pN->pRightChild_);
	}

	Node *pRoot_;
	int iCurNodeNum_;
	const int iMaxNodeNum_;
};

int main() {
	int iNodeNum;
	cin >> iNodeNum;

	//èâä˙âª
	Tree trNodeTree(iNodeNum);

	//Ç±ÇÃíÜÇ≈ì¸óÕÇ≥ÇÍÇÈ
	trNodeTree.setNodeValue();

	return 0;
}