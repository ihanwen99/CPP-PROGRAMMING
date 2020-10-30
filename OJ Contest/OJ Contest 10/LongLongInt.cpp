#include<iostream>
using namespace std;


#include<string>
#include<deque>

class LongLongInt {
	friend LongLongInt operator+(const LongLongInt& number1, const LongLongInt& number2);
	friend LongLongInt operator-(const LongLongInt& number1, const LongLongInt& number2);
	friend ostream& operator<<(ostream& os, const LongLongInt& number);
private:
	deque<int> value;
	void reduce();
public:
	LongLongInt(const char* num) {
		char* tmp = const_cast<char*> (num);
		while (*tmp != '\0') {
			value.push_front(*tmp - '0');
			tmp++;
		}
	};
	LongLongInt(const LongLongInt& other) {
		for (int i = 0; i < other.value.size(); i++) {
			value.push_back(other.value[i]);
		}
	};
};

void LongLongInt::reduce() {
	int length = this->value.size();
	for (int i = length - 1; i >= 0; i--) {
		if (this->value[i] != 0) { break; }
		this->value.pop_back();
	}
	if (this->value.empty()) { this->value.push_back(0); }
}

LongLongInt operator+(const LongLongInt& number1, const LongLongInt& number2) {
	LongLongInt tmp(number1);
	tmp.value.clear();

	int carry = 0;
	int length1 = number1.value.size(), length2 = number2.value.size();
	int upIDX = 0, downIDX = 0;
	int up, down;
	while (upIDX < length1 and downIDX < length2) {
		up = number1.value[upIDX++];
		down = number2.value[downIDX++];
		tmp.value.push_back((up + down + carry) % 10);
		carry = (up + down + carry) / 10;
	}
	while (upIDX < length1) {
		up = number1.value[upIDX++];
		tmp.value.push_back((up + carry) % 10);
		carry = (up + carry) / 10;
	}

	while (downIDX < length2) {
		down = number2.value[downIDX++];
		tmp.value.push_back((down + carry) % 10);
		carry = (down + carry) / 10;
	}

	if (carry == 1) { tmp.value.push_back(carry); }
	return tmp;
}

LongLongInt operator-(const LongLongInt& number1, const LongLongInt& number2) {
	LongLongInt tmp(number1);
	tmp.value.clear();

	int length = number2.value.size();
	int up, down;
	int burrow = 0;
	for (int i = 0; i < length; i++) {
		up = number1.value[i] - burrow;
		down = number2.value[i];
		burrow = up < down;
		tmp.value.push_back(up - down + burrow * 10);
	}
	for (int i = length; i < number1.value.size(); i++) {
		up = number1.value[i] - burrow;
		burrow = up < 0;
		tmp.value.push_back(up + burrow * 10);
	}
	tmp.reduce();
	return tmp;
}
ostream& operator<<(ostream& os, const LongLongInt& number) {
	int length = number.value.size();
	for (int i = length - 1; i >= 0; i--) { os << number.value[i]; }
	return os;
}

int main() {
	char num[100]; cin >> num;
	LongLongInt l1(num);
	cout << "1 :" << l1 << endl;

	cin >> num;
	LongLongInt l2(num);
	cout << "2 :" << l2 << endl;

	LongLongInt l3(l2);
	cout << "3 :" << l3 << endl;


	cout << l1 + l2 << endl;
	cout << l1 - l2 << endl;
}