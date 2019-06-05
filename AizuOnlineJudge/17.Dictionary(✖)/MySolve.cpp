//#include<iostream>
//#include<string>
//using namespace std;
//
//bool search(string d[], int num, string messa) {
//	int i = 0;
//	d[num] = messa;
//	while (d[i] != messa) i++;
//	if (i != num) return true;
//	return false;
//}
//
//void dumpList(string answer[], int num) {
//	for (int i = 0; i < num; i++) {
//		cout << answer[i] << endl;
//	}
//}
//int main() {
////	const int MAX = 1000000+1;
//	string dictionary[1000000];
//	string answer[1000000];
//	int num;
//	int dicMaxPoint;
//	int ansMaxPoint;
//	dicMaxPoint = 0;
//	ansMaxPoint = 0;
//
//	cin >> num;
//	for (int i = 0; i < num; i++ ) {
//		string command;
//		string message;
//		cin >> command;
//		cin >> message;
//		if (command[0] == 'i') {
//			dictionary[dicMaxPoint++] = message;
//		}
//		else {
//			if (search(dictionary, dicMaxPoint, message)) {
//				answer[ansMaxPoint++] =  "yes";
//			}
//			else {
//				answer[ansMaxPoint++] = "no";
//			}
//		}
//	}
//
//	dumpList(answer, ansMaxPoint);
//	return 0;
//}