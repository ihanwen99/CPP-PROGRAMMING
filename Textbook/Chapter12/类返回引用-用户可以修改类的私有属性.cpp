#include<iostream>
using namespace std;

class Time {
	int hour, minute, second;
public:
	Time(int = 0, int = 0, int = 0);
	void setTime(int, int, int);
	int getHour();
	int& setHour(int);
};

Time::Time(int h, int m, int s) {
	setTime(h, m, s);
}

void Time::setTime(int h, int m, int s) {
	hour = (h >= 0 and h < 24) ? h : 0;
	minute = (m >= 0 and m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;
}

int Time::getHour() { return hour; }
int& Time::setHour(int h) {
	hour = (h >= 0 and h < 24) ? h : 0;
	return hour;
}

int main() {
	Time t;
	int& hourRef = t.setHour(20);
	cout << hourRef << endl;

	hourRef = 30;
	cout << t.getHour() << endl;

	t.setHour(12) = 74;
	cout << t.getHour() << endl;

	return 0;
}