#include<iostream>
using namespace std;

bool isLeapYear(int year) {
	return (year % 400 == 0) or (year % 4 == 0 and year % 100 != 0);
}
int main() {
	int year, month, day; cin >> month >> day >> year;
	int monthDays[] = { 0, 31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	bool valid = true;
	if (month <= 0 || month > 12) { valid = false; }
	if ((day <= 0) or (day > monthDays[month])) { valid = false; }

	if (!valid) { cout << 0 << endl; return 0; }
	int totalDays = day;
	for (int m = 1; m < month; m++) {
		totalDays += monthDays[m];
	}
	cout << totalDays << endl;
	return 0;
}