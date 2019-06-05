#include <iostream>
#include <set>
using namespace std;

void print(set<int> s) {
	cout << s.size() << ":";
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << " " << *it;
	}
	cout << endl;
}

int main() {
	set<int> set;

	set.insert(8);
	set.insert(1);
	set.insert(7);
	set.insert(4);
	set.insert(8);
	set.insert(4);
	print(set);

	set.erase(7);
	print(set);

	set.insert(2);
	print(set);

	if (set.find(10) == set.end()) cout << "not found" << endl;
	int a = *(set.find(4));
	cout << a << endl;

	return 0;
}

