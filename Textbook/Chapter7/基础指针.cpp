#include<iostream>
#include<string>
using namespace std;

int main() {
	int* intp;
	int x = 2;
	intp = &x;
	cout << *intp << endl;
	return 0;
}