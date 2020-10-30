#include<iostream>
using namespace std;

#include<string>
class Employee {
public:
	string first_name;
	string last_name;
	string id;
	Employee(string first_name, string last_name, string id) {
		this->first_name = first_name;
		this->last_name = last_name;
		this->id = id;
	}
	virtual void print() = 0;
	virtual int earnings() = 0;
	virtual void virtualPrint() {
		print(); cout << "\nearned $" << earnings() << "\n\n";
	};
};

void virtualViaPointer(Employee* worker) {
	worker->virtualPrint();
}

void virtualViaReference(Employee& worker) {
	worker.virtualPrint();
}

class SalariedEmployee :public Employee {
private:
	int salary;
public:
	SalariedEmployee(string first_name, string last_name, string id, int salary) :Employee(first_name, last_name, id) { this->salary = salary; }
	void print() {
		cout << "salaried employee: " << first_name << ' ' << last_name << endl;
		cout << "social security number: " << id << endl;
		cout << "weekly salary: " << salary;
	}
	int earnings() {
		return salary;
	}
};

class HourlyEmployee :public Employee {
private:
	int hours;
	double hour_salary;
public:
	HourlyEmployee(string first_name, string last_name, string id, double hour_salary, int hours) :Employee(first_name, last_name, id) { this->hour_salary = hour_salary; this->hours = hours; }
	void print() {
		cout << "hourly employee: " << first_name << ' ' << last_name << endl;
		cout << "social security number: " << id << endl;
		cout << "hourly wage: " << hour_salary << "; " << "hours worked: " << hours;
	}
	int earnings() {
		return hours * hour_salary;
	}
};

class CommissionEmployee :public Employee {
private:
	int commission;
	double commission_rate;
public:
	CommissionEmployee(string first_name, string last_name, string id, int commission, double commission_rate) :Employee(first_name, last_name, id) { this->commission = commission; this->commission_rate = commission_rate; }
	void print() {
		cout << "commission employee: " << first_name << ' ' << last_name << endl;
		cout << "social security number: " << id << endl;
		cout << "gross sales: " << commission << "; " << "commission rate: " << commission_rate;
	}
	int earnings() {
		return commission * commission_rate;
	}
};

class BasePlusCommissionEmployee :public Employee {
private:
	int base;
	int commission;
	double commission_rate;
public:
	BasePlusCommissionEmployee(string first_name, string last_name, string id, int commission, double commission_rate, int base) :Employee(first_name, last_name, id) { this->commission = commission; this->commission_rate = commission_rate; this->base = base; }
	void print() {
		cout << "base-salaried commission employee: " << first_name << ' ' << last_name << endl;
		cout << "social security number: " << id << endl;
		cout << "gross sales: " << commission << "; " << "commission rate: " << commission_rate << "; " << "base salary: " << base;
	}
	int earnings() {
		return base + commission * commission_rate;
	}
};


int main() {
	// create derived-class objects
	SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", 800);
	HourlyEmployee hourlyEmployee("Karen", "Price", "222-22-2222", 16.75, 40);
	CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06);
	BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300);

	cout << "Employees processed individually using static binding:\n\n";

	// output each Employee's information and earnings using static binding
	salariedEmployee.print();
	cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
	hourlyEmployee.print();
	cout << "\nearned $" << hourlyEmployee.earnings() << "\n\n";
	commissionEmployee.print();
	cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
	basePlusCommissionEmployee.print();
	cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";

	// create array of four base-class pointers
	Employee* employees[4];

	// initialize array with Employees
	employees[0] = &salariedEmployee;
	employees[1] = &hourlyEmployee;
	employees[2] = &commissionEmployee;
	employees[3] = &basePlusCommissionEmployee;

	cout << "Employees processed polymorphically via dynamic binding:\n\n";

	// call virtualViaPointer to print each Employee's information
	// and earnings using dynamic binding
	cout << "Virtual function calls made off base-class pointers:\n\n";

	for (int i = 0; i < 4; i++)
		virtualViaPointer(employees[i]);

	// call virtualViaReference to print each Employee's information
	// and earnings using dynamic binding
	cout << "Virtual function calls made off base-class references:\n\n";

	for (int i = 0; i < 4; i++)
		virtualViaReference(*employees[i]); // note dereferencing

	return 0;
}