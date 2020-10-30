#include<iostream>
#include<string>
using namespace std;


int* max(int* a, int* b, int* c) {
	if (*a > * b) {
		if (*a > * c)return(a);
		else return(c);
	}
	else if (*b > * c) {
		return(b);
	}
	else return(c);
}

int* min(int* a, int* b, int* c) {
	if (*a < *b) {
		if (*a < *c)return(a);
		else return(c);
	}
	else if (*b < *c) { return(b); }
	else return(c);
}

void swap(int* a, int* b)
{
	int c;
	c = *a; *a = *b; *b = c;
}

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	cout << endl << x << y << z;
	swap(max(&x, &y, &z), min(&x, &y, &z));
	cout << endl << x << y << z;
	return 0;
}