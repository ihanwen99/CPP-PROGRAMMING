#include<iostream>
#include<string>
using namespace std;

template <class T>
T power(T base, int exponent){
	T result = base;
	if (exponent == 0) return (T)1;
	if (exponent < 0) return (T)0;
	while (--exponent) result *= base;
	return result;
}

int main(){
	int i = power(5, 4);
	long long int l = power((long long int)1000, 3);
	double d = power(1e5, 2);
	cout << "i=" << i << endl;
	cout << "l=" << l << endl;
	cout << "d=" << d << endl;
	return 0;
}