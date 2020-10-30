#include<iostream>
using namespace std;

class Rational {
private:
	int num;
	int den;
	void ReductFraction();

public:
	void create(int n, int d) { num = n; den = d; }
	void add(const Rational& r1, const Rational& r2);
	void multi(const Rational& r1, const Rational& r2);
	void display() { cout << num << '/' << den; }
};

void Rational::add(const Rational& r1, const Rational& r2) {
	num = r1.num * r2.den + r2.num * r1.den;
	den = r1.den * r2.den;
	ReductFraction();
}

void Rational::multi(const Rational& r1, const Rational& r2) {
	num = r1.num * r2.num;
	den = r1.den * r2.den;
	ReductFraction();
}

void Rational::ReductFraction() {
	int tmp = (num > den) ? den : num;
	for (; tmp > 1; --tmp) {
		if (num % tmp == 0 && den % tmp == 0) {
			num /= tmp;
			den /= tmp;
			break;
		}
	}
}

int main() {
	Rational r;
	r.create(2, 3);
	r.display();
}