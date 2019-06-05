#define _USE_MATH_DEFINES
#include<iostream>
#include<math.h>
using namespace std;

const float TH = 60.0 * M_PI/180.0;

typedef struct {
	float x;
	float y;
} Vertex;

void Koch(int d, Vertex p1, Vertex p2);

int main() {
	int deep;
	Vertex p1;
	Vertex p2;
	p1.x = 0; p1.y = 0;
	p2.x = 100; p2.y = 0;
	cin >> deep;

	cout << p1.x << " " << p1.y << endl;
	Koch(deep, p1, p2);
	cout << p2.x << " " << p2.y << endl;

	return 0;
}

void Koch(int d, Vertex p1, Vertex p2) {
	if (d <= 0) {
		return;
	}

	Vertex s, t, u;
	s.x = (2 * p1.x + 1 * p2.x) / 3;
	s.y = (2 * p1.y + 1 * p2.y) / 3;
	t.x = (1* p1.x + 2 * p2.x) / 3;
	t.y = (1 * p1.y + 2 * p2.y) / 3;
	u.x = (t.x - s.x)*cos(TH) - (t.y - s.y)*sin(TH) + s.x;
	u.y = (t.x - s.x)*sin(TH) + (t.y - s.y)*cos(TH) + s.y;

	Koch(d - 1, p1, s);
	cout << s.x << " " << s.y << endl;
	Koch(d - 1, s, u);
	cout << u.x << " " << u.y << endl;
	Koch(d - 1, u, t);
	cout << t.x << " " << t.y << endl;
	Koch(d - 1, t, p2);

	return;
}
