#include<iostream>
using namespace std;

int main() {
	cout << (-2 < -1 < 0) << endl; //实际先执行 -2<-1 得到 true(1)，然后 1 再和 0 比较；
	return 0;
}