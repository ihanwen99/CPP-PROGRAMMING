#include<iostream>
using namespace std;

class test {
private:
	int a;
public:
	test(int tmp = 0) { a = tmp; }
	test operator=(const test& tmptest) { a = tmptest.a; return *this; }
};
int main() {
	test a(2), b, c;
	b = c = a;
	return 0;
}