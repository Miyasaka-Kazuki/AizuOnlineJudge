#include<iostream>
using namespace std;

struct Card {
	int value[36];
	char suit[36];
};

bool BubbleSort(Card bubbleCard, int num);
bool SelectionSort(Card selectionCard, int num);

int main() {
	int num; //枚数
	Card bubbleCard;
	Card selectionCard;

	//入力
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> bubbleCard.suit[i];
		cin >> bubbleCard.value[i];
		selectionCard.suit[i] = bubbleCard.suit[i];
		selectionCard.value[i] = bubbleCard.value[i];
	}

	//計算
	bool bubbleStable = BubbleSort(bubbleCard, num);
	bool selectionStable = SelectionSort(selectionCard, num);

	//出力
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

//ｊは必ずiの後ろ。bはかならずaの後ろ。で全探索する。
//数字が等しいのを見つけたら、それがソートした後も順番が
//変わってないか調べる。
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

