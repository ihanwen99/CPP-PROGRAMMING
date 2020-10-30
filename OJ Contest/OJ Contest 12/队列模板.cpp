#include<iostream>
using namespace std;

#include<queue>
template<class T>
class myQueue {
	friend ostream& operator<<(ostream& os, const myQueue& que) {
		myQueue tmp = que;
		while (tmp.q.size() > 1) {
			os << tmp.pop() << ' ';
		}
		os << tmp.pop();
		return os;
	}
private:
	queue<T> q;
public:
	myQueue() {  }
	void push(T element) { q.push(element); }
	T pop() { T tmp = q.front(); q.pop(); return tmp; }

	T& first() { T& tmp = q.front(); return tmp; }
};


int main() {
	myQueue<int> q;
	int num[] = { 1,2,3,4 }, i;
	for (i = 0; i <= 3; i++)
	{
		q.push(num[i]);
	}
	cout << q << endl;;
	q.push(8);
	q.push(7);
	cout << q << endl;
	cout << q.pop() << endl;
	cout << q << endl;
	cout << q.first() << endl;
	cout << q << endl;
	return 0;
}
