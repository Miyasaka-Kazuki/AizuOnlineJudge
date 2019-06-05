//#include<iostream>
//#include<string>
//#include <strstream>
//using namespace std;
//
//class myStack {
//public:
//	void push(int x) {
//		S[++top] = x;
//	}
//	int pop() {
//		top--;
//		return S[top + 1];
//	}
//
//private:
//	int top = 0;
//	int S[1000] = { 0 };
//};
//
//int main() {
//	char s[100];
//	myStack sta;
//
//	while ((s = cin.get()) != istream::traits_type::eof()) {
//		if (s[0] == '\n' || *s == ' ') {
//			continue;
//		} 
//		else if (s[0] == '+') {
//			int a = sta.pop();
//			int b = sta.pop();
//			sta.push(b + a);
//			cout << "‚ " << endl;
//		}
//		else 	if (s[0] == '-') {
//			int a = sta.pop();
//			int b = sta.pop();
//			sta.push(b - a);
//			cout << "‚¢" << endl;
//		}
//		else 	if (s[0] == '*') {
//			int a = sta.pop();
//			int b = sta.pop();
//			sta.push(b * a);
//			cout << "‚¤" << endl;
//		}
//		else {
//			istrstream istr(s);
//			int i;
//			istr >> i;
//			sta.push(i);
//			cout << "‚¦" << endl;
//		}
//
//		cout << "‚¨" << endl;
//	}
//
//	cout << sta.pop() << endl;
//
//	return 0;
//}