#include<iostream>
#include<vector>
using namespace std;

void print(vector<double> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	vector<double> vec;
	
	vec.push_back(0.1);
	vec.push_back(0.2f);
	vec.push_back(0.3);
	vec[2] = 0.4;
	print(vec);

	vec.insert(vec.begin()+2, 0.8);
	print(vec);

	vec.erase(vec.begin() + 1);
	print(vec);

	vec.push_back(0.9);
	print(vec);

	return 0;
}