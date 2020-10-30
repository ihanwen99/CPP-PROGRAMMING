#include<iostream>
using namespace std;

class test {
private:
	int a;
public:
	test(int tmp = 0) { a = tmp; }
	void operator=(const test& tmptest) { a = tmptest.a; }
};
int main(){
	test a(2), b, c;
	b = a;
	c = a;
	return 0;//这个是可以的
}