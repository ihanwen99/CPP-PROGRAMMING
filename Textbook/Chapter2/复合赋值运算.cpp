#include<iostream>
using namespace std;

int main() {
	int salary = 10;
	salary *= 2 + 100;//10*(2+100)运算有优先级
	cout << salary << endl;
}