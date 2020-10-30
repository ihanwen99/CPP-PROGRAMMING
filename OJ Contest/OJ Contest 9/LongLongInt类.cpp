#include<iostream>
using namespace std;

#include<deque>
#include<string>
class LongLongInt {
private:
	char* num;
public:
	LongLongInt(char* num) {
		this->num = num;
	};

	LongLongInt(const LongLongInt& lli) {
		int length = strlen(lli.num);
		this->num = new char[length + 1];
		for (int i = 0; i < length; i++) { this->num[i] = lli.num[i]; }
		this->num[length] = '\0';
	};

	void display() {
		cout << num << endl;
	};

	LongLongInt add(LongLongInt b) {
		int lengtha = strlen(this->num);
		int lengthb = strlen(b.num);
		deque<char>tmp;
		if (lengtha > lengthb) {
			tmp = addNum(this->num, lengtha, b.num, lengthb);
		}
		else { tmp = addNum(b.num, lengthb, this->num, lengtha); }

		int length = tmp.size();
		char* address = new char[length + 1];
		for (int i = 0; i < length; i++) { address[i] = tmp[i]; }
		address[length] = '\0';
		LongLongInt result(address);
		return result;
	}

	deque<char> addNum(char* a, int la, char* b, int lb) {
		deque<char> tmp;
		int carry = 0;
		int  value;
		while(lb>=1) {
			value = *(a + la - 1) + *(b + lb - 1) - '0' - '0' + carry;
			carry = value / 10;
			tmp.push_front(value % 10 + '0');
			la--; lb--;
		}
		while(la>=1){
			value = *(a + la - 1) - '0' + carry;
			carry = value / 10;
			tmp.push_front(value % 10 + '0');
			la--;
		}
		if (carry == 1) { tmp.push_front('1'); }
		return tmp;
	}
};

int main() {
	string aa, bb;
	cin >> aa >> bb;
	char* aaa = const_cast<char*>(aa.c_str()), * bbb = const_cast<char*>(bb.c_str());
	LongLongInt a(aaa), b(bbb);
	LongLongInt c = a.add(b);
	c.display();


	return 0;
}