#include<iostream>
using namespace std;

class point {
	int x, y;
public:
	point(int a, int b) { x = a; y = b; }
	point(const point& p) { x = 2 * p.x; y = p.y; }
	void print() {
		cout << x << " " << y << endl;
	}
};
int main() {
	point p1(10, 20), p2(p1), p3 = p1, p4(1, 2);
	p1.print(); p2.print(); p3.print(); p4.print();
	p4 = p1; p4.print(); return 0;
}