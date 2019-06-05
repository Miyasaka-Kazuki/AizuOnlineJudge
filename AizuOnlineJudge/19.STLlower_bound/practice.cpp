//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	const int N = 14;
//	int A[N] = { 1, 1, 2, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15 };
//	int *pos;
//	int idx;
//
//	pos = lower_bound(A, A+N, 5);
//	idx = distance(A, pos);
//	cout << "A[" << idx << "] = " << *pos << endl;
//
//	pos = lower_bound(A, A + N, 2);
//	idx = distance(A, pos);
//	cout << "A[" << idx << "] = " << *pos << endl;
//
//	return 0;
//}