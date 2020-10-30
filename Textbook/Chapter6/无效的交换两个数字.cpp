#include<iostream>
#include<string>
using namespace std;

void swap(int a, int b){
	int c;
	c = a; a = b; b = c;
}
int main()
{
	int a = 5, b = 6;
	swap(a, b);
	cout << a << ' ' << b << endl;
	return 0;
}