#include<iostream>
using namespace std;

#include<iomanip>
class SavingAccount {
	double money;
	int id;
	double rate = 0.05;
	static int count;

public:
	SavingAccount(int money) :money(money) { id = ++count; };
	void display() { cout << id << ' '  << fixed << showpoint << setprecision(2)<< money << ' ' << rate << endl; }
	void calculate() { money *= (1 + rate); }
	void changerate(double new_rate) { rate = new_rate; }
};

int SavingAccount::count = 0;
int main() {
	// 1st month
	int first_money, second_money;
	cin >> first_money >> second_money;
	SavingAccount first(first_money);
	SavingAccount second(second_money);
	first.display();
	second.display();

	// 2nd month
	float new_rate;
	cin >> new_rate;
	first.calculate();
	first.display();
	second.calculate();
	second.display();
	first.changerate(new_rate);
	second.changerate(new_rate);

	// 3rd month
	int third_money;
	cin >> third_money;
	first.calculate();
	first.display();
	second.calculate();
	second.display();
	SavingAccount* p = new SavingAccount(third_money);

	// 4th month
	first.calculate();
	first.display();
	second.calculate();
	second.display();
	p->calculate();
	p->display();

	delete p;
	return 0;
}