#include<iostream>
using namespace std;


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


int main() {
	Date date0;
	Date date1(12, 31, 2012);
	cout << date0 << endl;
	cout << date1 << endl;
	cout << ++date1 << endl;
	cout << date1++ << endl;
	cout << date1 << endl;
	cout << (date0 < date1) << endl;
	cout << (date1 += 100) << endl;
}