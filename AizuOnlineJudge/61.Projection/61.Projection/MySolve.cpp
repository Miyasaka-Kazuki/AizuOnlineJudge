#include <iostream>
#include <cstdlib>
using namespace std;

//#define equals( a, b ) (fabs((a) - (b)) < DBL_E)

class Vector2 {
public:
	Vector2(double x_, double y_) : x(x_), y(y_) {}
	Vector2() : x(0), y(0) {}
	Vector2 operator - (Vector2 other) {
		return Vector2(x - other.GetX(), y - other.GetY());
	}
	Vector2 operator + (Vector2 other) {
		return Vector2(x + other.GetX(), y + other.GetY());
	}
	Vector2 operator * (double other) {
		return Vector2(other * x, other * y);
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

double Norm(Vector2 vec) {
	return sqrt(vec.GetX() * vec.GetX() + vec.GetY() * vec.GetY());
}

bool IsOrthogonal(Vector2 vecA, Vector2 vecB) {
	double ans = Dot(vecA, vecB);
	//	return equals(ans, 0.0);
	//	return (fabs(ans) < DBL_EPSILON);
	ans = ans > 0 ? ans : -ans;
	return (ans < 0.1f);
}

bool IsParallel(Vector2 vecA, Vector2 vecB) {
	double ans = CrossY(vecA, vecB);
	//	return (fabs(ans) < DBL_EPSILON);
	ans = ans > 0 ? ans : -ans;
	return (ans < 0.1f);
}

int main() {
	int query;
	Vector2 vecs[2];

	for (int i = 0; i < 2; i++) {
		double x, y;
		cin >> x >> y;
		vecs[i].SetVector2(x, y);
	}
	Vector2 base = vecs[1] - vecs[0];
	base.SetVector2(base.GetX() / Norm(base), base.GetY() / Norm(base));

	cin >> query;

	for (int i = 0; i < query; i++) {
		Vector2 vecAns;
		double x, y;
		cin >> x >> y;
		vecAns.SetVector2(x, y);

		Vector2 ans = base * Dot(base, vecAns);
		ans = ans + vecs[0];
		cout << ans.GetX() << " " << ans.GetY() << endl;
	}

	return 0;
}