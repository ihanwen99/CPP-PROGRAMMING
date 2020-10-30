#include <iostream> 
using namespace std;

#include<vector>
class mystack {
private:
	int maxSize;
	vector<int> values;
public:
	mystack(int size = 100) :maxSize(size) {}
	bool isempty() { return values.size() == 0; }
	bool isfull() { return values.size() == maxSize; }
	bool push(int number) {
		if (this->isfull()) { return false; }
		values.push_back(number);
		return true;
	}
	bool pop(int& number) {
		if (this->isempty()) { return false; }
		number = values.back();
		values.pop_back();
		return true;
	}
};

int main() {
	int num[] = { 1,3,5,7,9,11 }, i, data;
	mystack s(5);
	cout << "The stack is empty: " << s.isempty() << endl;
	cout << "The stack is full: " << s.isfull() << endl;
	for (i = 0; i <= 5; i++)
	{
		if (s.push(num[i]))
			cout << "Push " << num[i] << " success!" << endl;
		else
			cout << "Push " << num[i] << " fail!" << endl;
	}
	cout << "The stack is empty: " << s.isempty() << endl;
	cout << "The stack is full: " << s.isfull() << endl;
	for (i = 0; i <= 5; i++)
	{
		if (s.pop(data))
			cout << "Pop " << data << " success!" << endl;
		else
			cout << "Pop fail!" << endl;
	}
	return 0;
}