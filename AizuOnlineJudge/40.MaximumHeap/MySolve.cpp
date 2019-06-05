#include <iostream>
using namespace std;

static const int cMaxNumber = 500001;

void maxHeapify(int array[], int interRoNode, int array_size) {
	int left = 2 * interRoNode;
	int right = 2 * interRoNode + 1;

	//最大の値のノードを選ぶ
	int largestNodeNumber;
	if (left <= array_size && array[left] > array[interRoNode])
		largestNodeNumber = left;
	else
		largestNodeNumber = interRoNode;
	if (right <= array_size && array[right] > array[largestNodeNumber])
		largestNodeNumber = right;

	//子のほうが大きいなら入れ替える
	if (largestNodeNumber != interRoNode) {
		swap(array[largestNodeNumber], array[interRoNode]);
		maxHeapify(array, largestNodeNumber, array_size);
	}
}

void buildMaxHeap(int array[], int array_size) {
	for (int i = array_size / 2; i >= 1; i--)
		maxHeapify(array, i, array_size);
}

int main() {
	int array[cMaxNumber];
	int array_size;

	cin >> array_size;
	for (int i = 1; i <= array_size; i++)
		cin >> array[i];

	buildMaxHeap(array, array_size);

	for (int i = 1; i <= array_size; i++) {
		cout << " " << array[i];
	}
	cout << endl;

	return 0;
}