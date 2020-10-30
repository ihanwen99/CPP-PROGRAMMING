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
	b = c = a;
	return 1;//这个编译错误，需要返回同类对象的引用
}