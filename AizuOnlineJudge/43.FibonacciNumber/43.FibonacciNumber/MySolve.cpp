#include <iostream>
using namespace std;

int fiboArray[44] = {0};
int fibonacci(int anySection) {
	if (anySection == 0 || anySection == 1)
		return (fiboArray[anySection] = 1);

	if (fiboArray[anySection] == 0) { //計算されてないなら
		fiboArray[anySection] = fibonacci(anySection - 1) + fibonacci(anySection - 2);
		return fiboArray[anySection];
	}
	else //すでに計算されているなら
		return fiboArray[anySection];
}

int main() {
	int anySection;
	cin >> anySection;

	int answer = fibonacci(anySection);

	cout << answer << endl;
	return 0;
}