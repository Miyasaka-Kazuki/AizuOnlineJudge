#include<iostream>
#include<string>
using namespace std;

const int MAX = 1000000;

int strToInt(string mes) {
	long long key;
	key = 0;
	for (int i = 0; i < mes.length(); i++) {
		if (mes[i] == 'A') {
			key += 1;
		}
		else if (mes[i] == 'C') {
			key += 2;
		}
		else if (mes[i] ==  'G') {
			key += 3;
		}
		else if (mes[i] == 'T') {
			key += 4;
		}
		else {
			return 0;
		}
		key = key << 1;
	}
	return key;
}

int h1(int key) {
	return key % MAX;
}

int h2(int key) {
	return 1 + (key % (MAX - 1));
}

void insertHash(string dic[], char message[]) {
	long long key;
	key = strToInt(message);
	int i = 0;
	while (true) {
		long long h = (h1(key) + i*h2(key)) % MAX;
		if (dic[h] == message) {
			return; //•¶Žš—ñ‚ª‚·‚Å‚É“ü‚Á‚Ä‚½‚ç‚È‚É‚à‚µ‚È‚¢
		}
		else if (dic[h] == "\0") {
			dic[h] = message;
			return;
		}
		else {
			i++;
		}
	}
}

bool findHash(string dic[], char message[]) {
	long long key;
	key = strToInt(message);
	int i = 0;
	while (true) {
		long long h = (h1(key) + i*h2(key)) % MAX;
		if (dic[h] == message) {
			return true;
		}
		else if (dic[h] == "\0") {
			return false; //\0‚Æ‚¢‚¤‚±‚Æ‚ÍÕ“Ë‚à‚µ‚Ä‚È‚¢‚Í‚¸‚È‚Ì‚É,
								 //‰½‚à‚Í‚¢‚Á‚Ä‚È‚¢‚Ì‚Å‚»‚Ì•¶Žš—ñ‚Í“ü‚Á‚Ä‚¢‚È‚¢B
		}
		else {
			i++;
		}
	}
	return false;
}

void dumpList(string answer[], int num) {
	for (int i = 0; i < num; i++) {
		printf("%s\n", answer[i].c_str());
	}
}
int main() {
	//	const int MAX = 1000000+1;
	string dictionary[MAX];
//	string answer[MAX];
	int num;
//	int dicMaxPoint;
	int ansMaxPoint;
//	dicMaxPoint = 0;
	ansMaxPoint = 0;
	for (int i = 0; i < MAX; i++) {
		dictionary[i] = "\0";
	}
//	cin >> num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		string command;
		string message;
		char com[12];
		char mes[12];
		//cin >> command;
		//cin >> message;
		scanf("%s", com);
		scanf("%s", mes);
//		command = com;
//		message = mes;
		if (com[0] == 'i') {
			insertHash(dictionary, mes);
		}
		else {
			if (findHash(dictionary, mes)) {
//				answer[ansMaxPoint++] = "yes";
				printf("yes\n");
			}
			else {
//				answer[ansMaxPoint++] = "no";
				printf("no\n");
			}
		}
	}

//	dumpList(answer, ansMaxPoint);
	return 0;
}