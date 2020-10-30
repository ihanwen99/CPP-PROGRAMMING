#include<iostream>
using namespace std;

#include<string>
#include<deque>

class LongLongInt {
	friend LongLongInt operator+(const LongLongInt& number1, const LongLongInt& number2);
	friend LongLongInt operator-(const LongLongInt& number1, const LongLongInt& number2);
	friend ostream& operator<<(ostream& os, const LongLongInt& number);
	friend bool operator>(const LongLongInt& number1, const LongLongInt& number2);
	friend bool operator==(const LongLongInt& number1, const LongLongInt& number2);
private:
	deque<int> value;
	void reduce();
public:
	LongLongInt() {
		value.push_front(0);
	}

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
	LongLongInt tmp;
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
	LongLongInt tmp;
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
bool operator>(const LongLongInt& number1, const LongLongInt& number2) {
	if (number1.value.size() > number2.value.size()) { return true; }
	if (number1.value.size() < number2.value.size()) { return false; }
	// equal length
	int size = number1.value.size();
	for (int i = size - 1; i >= 0; i--) {
		if (number1.value[i] > number2.value[i]) { return true; }
		if (number1.value[i] == number2.value[i]) { continue; }
		if (number1.value[i] < number2.value[i]) { return false; }
	}
}
bool operator==(const LongLongInt& number1, const LongLongInt& number2) {
	return number1.value == number2.value;
}

class signLLI : public LongLongInt {
	friend signLLI operator+(const signLLI& number1, const signLLI& number2);
	friend signLLI operator-(const signLLI& number1, const signLLI& number2);
	friend ostream& operator<<(ostream& os, const signLLI& number);
private:
	int sign;
public:
	signLLI(const char* num) :LongLongInt((*num == '-' ? num + 1 : num)) { sign = (*num == '-') ? -1 : 1; }
	signLLI() { sign = 1; }
};

signLLI operator+(const signLLI& signNumber1, const signLLI& signNumber2) {
	signLLI tmp;
	LongLongInt& number = tmp;

	bool positive1 = (signNumber1.sign == 1);
	bool positive2 = (signNumber2.sign == 1);
	const LongLongInt& number1 = signNumber1;
	const LongLongInt& number2 = signNumber2;

	//cout << "number1: " << number1 << endl; cout << "number2 " << number2 << endl;

	if (positive1 and positive2) { tmp.sign = 1; number = number1 + number2; }
	if (not positive1 and not positive2) { tmp.sign = -1; number = number1 + number2; }
	// one positive(contains 0) and one negative
	if (positive1 + positive2 == 1) {
		if (number1 == number2) { tmp.sign = 1; }
		else if (number1 > number2) {
			tmp.sign = signNumber1.sign;
			number = number1 - number2;
		}
		else {
			tmp.sign = signNumber2.sign;
			number = number2 - number1;
		}
	}
	//cout << "result: " << number << endl;
	return tmp;
}
signLLI operator-(const signLLI& signNumber1, const signLLI& signNumber2) {
	signLLI tmp;
	LongLongInt& number = tmp;

	bool positive1 = (signNumber1.sign == 1);
	bool positive2 = (signNumber2.sign == 1);
	const LongLongInt& number1 = signNumber1;
	const LongLongInt& number2 = signNumber2;

	//cout << "number1: " << number1 << endl; cout << "number2 " << number2 << endl;

	if (positive1 and not positive2) { tmp.sign = 1; number = number1 + number2; }
	if (not positive1 and positive2) { tmp.sign = -1; number = number1 + number2; }
	if (positive1 and positive2) {
		if (number1 == number2) { tmp.sign = 1; }
		else if (number1 > number2) {
			tmp.sign = 1;
			number = number1 - number2;
		}
		else {
			tmp.sign = -1;
			number = number2 - number1;
		}
	}
	if (not positive1 and not positive2) {
		if (number1 == number2) { tmp.sign = 1; }
		else if (number1 > number2) {
			// Actually, this branch is number1<number2
			tmp.sign = -1;
			number = number1 - number2;
		}
		else {
			tmp.sign = 1;
			number = number2 - number1;
		}
	}
	//cout << "result: " << number << endl;
	return tmp;
}
ostream& operator<<(ostream& os, const signLLI& signNumber) {
	LongLongInt number = signNumber;
	if (signNumber.sign == -1) { os << "-"; }
	os << number;
	return os;
}

int main() {
	signLLI a("-100"), b("-130"), c("70");
	cout << a << endl << b << endl << c << endl;
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a + b + c << endl;
	return 0;
}