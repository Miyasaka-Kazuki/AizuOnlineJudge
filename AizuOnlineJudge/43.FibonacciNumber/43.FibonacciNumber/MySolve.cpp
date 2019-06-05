#include <iostream>
using namespace std;

int fiboArray[44] = {0};
int fibonacci(int anySection) {
	if (anySection == 0 || anySection == 1)
		return (fiboArray[anySection] = 1);

	if (fiboArray[anySection] == 0) { //ŒvŽZ‚³‚ê‚Ä‚È‚¢‚È‚ç
		fiboArray[anySection] = fibonacci(anySection - 1) + fibonacci(anySection - 2);
		return fiboArray[anySection];
	}
	else //‚·‚Å‚ÉŒvŽZ‚³‚ê‚Ä‚¢‚é‚È‚ç
		return fiboArray[anySection];
}

int main() {
	int anySection;
	cin >> anySection;

	int answer = fibonacci(anySection);

	cout << answer << endl;
	return 0;
}