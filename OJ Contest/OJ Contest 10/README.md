# OJ Contest 10

训练题目内容对应书上第十一章。

---

### 1. Date

> 创建一个`Date`类，这个类需要完成以下的功能：
>
> 1. 包含年月日信息；
> 2. 可以设定日期，需要检查日期的合法性
> 3. 能够增加1天(++)、增加任意正整数天(+=)
> 4. 日期间的比较、输出

比较基础，按部就班的写就可以了。

[我的完整代码](https://github.com/david990917/My-Computer-Science-Learning/blob/master/CPP-Programming-Course/OJ%20Contest%2010/Date.cpp)

```cpp
#include <iomanip>
class Date {
	friend bool operator<(const Date& date1, const Date& date2) {
		if (date1.year < date2.year) { return true; }
		else {
			if (date1.month < date2.month) { return true; }
			else {
				if (date1.day < date2.day) { return true; }
			}
		}
		return false;
	}

	friend ostream& operator<<(ostream& os, const Date date) {
		os << setfill('0') << setw(4) << date.year << '-' << setw(2) << date.month << '-' << setw(2) << date.day;
		return os;
	}
private:
	int year;
	int month;
	int day;
public:
	//Defaults to 1900-01-01
	Date() { year = 1900; month = 1; day = 1; }

	//Initial Date, if invalid switch to 1900-01-01
	Date(int m, int d, int y) {
		bool valid = isValidDate(y, m, d);
		if (!valid) { cout << "Invalid date." << endl; year = 1900; month = 1; day = 1; }
		else { year = y; month = m; day = d; }
	}

	bool isLeapYear(int year) { return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0); }
	bool isValidDate(int y, int m, int d) {
		bool valid = true;
		int monthDate[] = { 0, 31, 28 + isLeapYear(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (m < 0 or m>12) { valid = false; }
		if (valid) {
			int normalDay = monthDate[m];
			if (d <= 0 or d > normalDay) { valid = false; }
		}
		return valid;
	}

	void setDate(int m, int d, int y) {
		bool valid = isValidDate(y, m, d);
		if (!valid) { cout << "Invalid date." << endl; }
		else { year = y; month = m; day = d; }
	}

	// Overload
	//  ++ (prefix and postfix) for increment 1 day
	//  += for adding positive amount of days.
	//  < for comparsion between dates
	//  << for output with cout, format: 1900-01-01, no new line

	Date& operator++() {
		int monthDate[] = { 0, 31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int normalDay = monthDate[month];
		if (day < normalDay) { day++; }
		else {
			if (month != 12) { month++; day = 1; }
			else { year++; month = 1; day = 1; }
		}
		return *this;
	}

	Date operator++(int) {
		Date tmp = *this;
		int monthDate[] = { 0, 31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int normalDay = monthDate[month];
		if (day < normalDay) { day++; }
		else {
			if (month != 12) { month++; day = 1; }
			else { year++; month = 1; day = 1; }
		}
		return tmp;
	}

	Date& operator+=(int n) {
		int monthDate[] = { 0, 31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		day += n;
		while (day > monthDate[month]) {
			day -= monthDate[month];
			if (month == 12) { year++; monthDate[2] = 28 + isLeapYear(year); month = 1; }
			else { month++; }
		}
		return *this;
	}

};
```



### 2. LongLongInt

> 实现支持高精度加减法的`LongLongInt`。使用运算符重载实现加、减（保证大数减小数）和输出。

第一次实现这样的减法，很奇妙，同时需要注意最后 0 情况的输出！

[我的完整代码](https://github.com/david990917/My-Computer-Science-Learning/blob/master/CPP-Programming-Course/OJ%20Contest%2010/LongLongInt.cpp)

##### 类的声明 - 友元

```cpp
friend LongLongInt operator+(const LongLongInt& number1, const LongLongInt& number2);
friend LongLongInt operator-(const LongLongInt& number1, const LongLongInt& number2);
friend ostream& operator<<(ostream& os, const LongLongInt& number);
```

##### 初始化

这里面为了遍历常量类型的字符数组，使用了 **const_cast<char*>()** 这样的方式显示进行转换。

```cpp
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
```

##### reduce - 处理零元

多余的零去掉；如果最后啥也没有了，补上一个 0 

```cpp
void LongLongInt::reduce() {
	int length = this->value.size();
	for (int i = length - 1; i >= 0; i--) {
		if (this->value[i] != 0) { break; }
		this->value.pop_back();
	}
	if (this->value.empty()) { this->value.push_back(0); }
}
```

##### 重载的加法

用很直白的方式写出来的，同时可以注意到可以合并相同的操作进行优化。

```cpp
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
```

##### 重载减法

```cpp
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
```

##### 重载输出

```cpp
ostream& operator<<(ostream& os, const LongLongInt& number) {
	int length = number.value.size();
	for (int i = length - 1; i >= 0; i--) { os << number.value[i]; }
	return os;
}
```