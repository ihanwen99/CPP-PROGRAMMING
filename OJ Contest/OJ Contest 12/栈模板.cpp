#include<iostream>
using namespace std;

template<class T>
class mystack {
	int maxSize;
	int currSize;
	T* values;
	void doubleSpace();
public:
	mystack(int size) :maxSize(size) { currSize = 0; values = new T[maxSize]; }
	void push(T element) {
		if (currSize == maxSize) { doubleSpace(); }
		values[currSize++] = element;
	}
	T pop() { return values[--currSize]; }
	bool isEmpty() { return currSize == 0; }
	~mystack() { delete[]values; }
};

template<class T>
void mystack<T>::doubleSpace() {
	maxSize *= 2;
	T* tmp = values;
	values = new T[maxSize];
	for (int i = 0; i < currSize; i++) {
		values[i] = tmp[i];
	}
}


int main() {
	mystack<char>stCh(4); //栈的初始规模为4
	for (int i = 0; i < 10; i++)    stCh.push('a' + i);
	while (!stCh.isEmpty()) cout << stCh.pop() << ' ';
	cout << endl;
	mystack<int>stint(4);
	for (int i = 0; i < 6; i++)      stint.push(i * i);
	while (!stint.isEmpty()) cout << stint.pop() << ' ';
	cout << endl;
	return 0;
}