#include<iostream>
using namespace std;

struct Card {
	int value[36];
	char suit[36];
};

bool BubbleSort(Card bubbleCard, int num);
bool SelectionSort(Card selectionCard, int num);

int main() {
	int num; //����
	Card bubbleCard;
	Card selectionCard;

	//����
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> bubbleCard.suit[i];
		cin >> bubbleCard.value[i];
		selectionCard.suit[i] = bubbleCard.suit[i];
		selectionCard.value[i] = bubbleCard.value[i];
	}

	//�v�Z
	bool bubbleStable = BubbleSort(bubbleCard, num);
	bool selectionStable = SelectionSort(selectionCard, num);

	//�o��
	for (int i = 0; i < num; i++) {
		if (i) cout << " ";
		cout << bubbleCard.suit[i];
		cout << bubbleCard.value[i];
	}
	cout << endl;
	if (bubbleStable) {
		cout << "Stable" << endl;
	}
	else {
		cout << "Not stable" << endl;
	}

	for (int i = 0; i < num; i++) {
		if (i) cout << " ";
		cout << selectionCard.suit[i];
		cout << selectionCard.value[i];
	}
	cout << endl;
	if (selectionStable) {
		cout << "Stable" << endl;
	}
	else {
		cout << "Not stable" << endl;
	}

	return 0;
}

//���͕K��i�̌��Bb�͂��Ȃ炸a�̌��B�őS�T������B
//�������������̂���������A���ꂪ�\�[�g����������Ԃ�
//�ς���ĂȂ������ׂ�B
bool beStable(Card in, Card out, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			for (int a = 0; a < num; a++) {
				for (int b = 0; b < num; b++) {
					if (in.value[i] == in.value[j] &&
						in.suit[i] == out.suit[b] &&
						in.suit[j] == out.suit[a]) {
						return false;
					}
				}
			}
		}
	}
	return true;
}
bool BubbleSort(Card bubbleCard, int num) {
	Card in, out;
	for (int i = 0; i < num; i++) {
		in.suit[i] = bubbleCard.suit[i];
		in.value[i] = bubbleCard.value[i];
	}

	for (int i = 0; i < num; i++)
		for (int j = num - 1; j > i; j--) {
			if (bubbleCard.value[j] < bubbleCard.value[j-1]) {
				swap(bubbleCard.value[j], bubbleCard.value[j-1]);
			}
		}

	return beStable(in, bubbleCard, num);
}

bool SelectionSort(Card selectionCard, int num) {
	Card in, out;
	for (int i = 0; i < num; i++) {
		in.suit[i] = selectionCard.suit[i];
		in.value[i] = selectionCard.value[i];
	}

	for (int i = 0; i < num; i++) {
		int min = i;
		for (int j = i + 1; j < num; j++) {
			if (selectionCard.value[j] < selectionCard.value[min]) {
				min = j;
			}
		}
		swap(selectionCard.value[i], selectionCard.value[min]);
	}

	return beStable(in, selectionCard, num);
}

