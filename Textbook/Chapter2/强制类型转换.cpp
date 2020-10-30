#include<iostream>
using namespace std;

int main() {
	double z;
	int x = 2, y = 3;
	z = (double)x / y;//0.6777
	cout << z << endl;

	z = (double)(x / y);//0
	cout << z << endl;
}