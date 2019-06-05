#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> vec) {
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it;
	}
	cout << endl;
}

int main() {
	int num = 4;
	vector<int> vec;

	for (int i = 0; i < num; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}

	print(vec);

	vector<int>::iterator it = vec.begin();
	*it = 3;
	it++;
	(*it)++;

	print(vec);

	return 0;
}