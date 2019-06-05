#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	stack<int> sta;
	string str;

	while (cin >> str){
		if (str[0] == '+') {
			int a = sta.top(); 
			sta.pop();
			int b = sta.top();
			sta.pop();
			sta.push(a+b);
		}
		else if (str[0] == '-') {
			int a = sta.top();
			sta.pop();
			int b = sta.top();
			sta.pop();
			sta.push(b - a);
		}
		else if (str[0] == '*') {
			int a = sta.top();
			sta.pop();
			int b = sta.top();
			sta.pop();
			sta.push(a * b);
		}
		else {
			sta.push(stoi(str.c_str()));
		}
	}

	cout << sta.top() << endl;
	return 0;
}