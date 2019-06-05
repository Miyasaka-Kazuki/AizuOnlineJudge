#include <iostream>
#include <cstdlib>
using namespace std;

//#define equals( a, b ) (fabs((a) - (b)) < DBL_E)

class Vector2 {
public:
	Vector2(double x_, double y_) : x(x_), y(y_) {}
	Vector2() : x(0), y(0) {}
	Vector2 operator -(Vector2& other) {
		Vector2 vec(x - other.GetX(), y - other.GetY());
		return vec;
	}
	void SetVector2(double x_, double y_) {
		x = x_;
		y = y_;
	}
	double GetX() {
		return x;
	}
	double GetY() {
		return y;
	}

private:
	double x, y;
};

double Dot(Vector2 vecA, Vector2 vecB) {
	return vecA.GetX() * vecB.GetX() + vecA.GetY() * vecB.GetY();
}

double CrossY(Vector2 vecA, Vector2 vecB) {
	return vecA.GetX() * vecB.GetY() - vecA.GetY() * vecB.GetX();
}

bool IsOrthogonal(Vector2 vecA, Vector2 vecB) {
    double ans = Dot(vecA, vecB);
//	return equals(ans, 0.0);
//	return (fabs(ans) < DBL_EPSILON);
	ans = ans > 0 ? ans : -ans;
	return ( ans < 0.1f);
}

bool IsParallel(Vector2 vecA, Vector2 vecB) {
	double ans = CrossY(vecA, vecB);
//	return (fabs(ans) < DBL_EPSILON);
	ans = ans > 0 ? ans : -ans;
	return (ans < 0.1f);
}

int main() {
	int query;
	cin >> query;

	for (int i = 0; i < query; i++) {
		Vector2 vecs[4];
		for (int i = 0; i < 4; i++) {
			double x, y;
			cin >> x >> y;
			vecs[i].SetVector2(x, y);
		}

		Vector2 vecA = vecs[1] - vecs[0];
		Vector2 vecB = vecs[3] - vecs[2];
		bool orth = IsOrthogonal(vecA, vecB);
		if (orth) {
			cout << 1 << endl;
			continue;
		}

		bool para = IsParallel(vecA, vecB);
		if (para) {
			cout << 2 << endl;
			continue;
		}
		cout << 0 << endl;
	}

	return 0;
}