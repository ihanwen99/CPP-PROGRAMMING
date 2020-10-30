#include<iostream>
using namespace std;

class point {
	int x, y;
public:
	point(int a, int b) { x = a; y = b; }
	//但是拷贝构造函数的时候是可以的，因为是在类里面的函数
	point(const point& p) { x = 2 * p.x; y = p.y; }
	void print() {
		cout << x << " " << y << endl;
	}
};
int main() {
	point p1(10, 20);
	//不能cin
	cin >> p1.x >> p1.y;
	return 0;
}