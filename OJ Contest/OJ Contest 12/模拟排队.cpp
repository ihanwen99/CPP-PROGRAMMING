#include <iostream>
using namespace std;

template <class elemType> class linkList;
template <class T> ostream& operator<<(ostream&, const linkList<T>&);
template <class elemType> class queues;
class client;
template <class elemType>

class node
{
	friend class linkList<elemType>;
	friend ostream& operator<<<>(ostream&, const linkList<elemType>&);
	friend  class queues<elemType>;
private:
	elemType  data;
	node <elemType>* next;
public:
	node(const elemType& x, node <elemType>* N = NULL)
	{
		data = x; next = N;
	}
	node() :next(NULL) {}
	~node() {}
};

template <class elemType>
class linkList
{
	friend ostream& operator<<<>(ostream&, const linkList<elemType>&);
protected:
	node <elemType>* head;
	void makeEmpty();
public:
	linkList() { head = new node<elemType>; }
	~linkList() { makeEmpty(); delete head; }
	void create(const elemType a);
};


template <class elemType>
class queues : public linkList<elemType>
{
public:
	queues() { this->head = new node<elemType>; }
	void push(const elemType data)
	{
		node <elemType>* p = new node<elemType>(data);
		p->next = this->head->next;   this->head->next = p;
	}
	bool pop(elemType data) //Õ»Îª¿ÕÊ±·µ»Øfalse¡£
	{
		node <elemType>* p = this->head->next;
		this->head->next = p->next;
		data = p->data;
		delete p;
		return true;
	}
	int status();
};

template <class elemType>
void linkList<elemType>::makeEmpty()
{
	node <elemType>* p = head->next, * q;
	head->next = NULL;
	while (p != NULL) { q = p->next; delete p;  p = q; }
}

template <class elemType>
void linkList<elemType>::create(elemType a)
{
	elemType tmp = a;
	node <elemType>* p, * q = head;
	p = new node<elemType>(tmp);
	q->next = p;
	q = p;
	q->next = NULL;
}

template <class T>
ostream& operator<<(ostream& os, const linkList<T>& obj)
{
	node <T>* q = obj.head->next;
	os << endl;
	while (q != NULL) { os << q->data;  q = q->next; }
	return os;
}

template <class T>
int queues<T>::status()
{
	node <T>* q = this->head->next;
	return q->data;
}

int paidui(int a[])
{
	int i = 2;
	int t = 0;
	int s1, s2;
	queues<int> q1, q2;
	q1.push(a[0]);
	q2.push(a[1]);
	s1 = q1.status();
	s2 = q2.status();
	while (s1 != 0 || s2 != 0)
	{
		if (i < 10)
		{//when both windows are not empty
			t++;
			s1--;
			s2--;
			if (s1 == 0)
			{
				q1.pop(2);
				q1.push(a[i]);
				s1 = q1.status();
				i++;
			}
			if (s2 == 0)
			{
				q2.pop(2);
				q2.push(a[i]);
				s2 = q2.status();
				i++;
			}
		}
		else
		{
			t++;
			if (s1 != 0)s1--;
			if (s2 != 0)s2--;
		}
	}
	return t;
}

int main()
{
	int temp = 0;
	for (int i = 0; i < 10; i++)
	{
		int customers[] = { 5,1,1,1,1,1,1,1,1,1 };//to change the position of the 5-min person
		temp = customers[0];
		customers[0] = customers[i];
		customers[i] = temp;
		for (int i = 0; i < 9; i++) {
			cout << customers[i] << ' ';
		}
		cout << customers[9];

		cout << endl << paidui(customers) << endl;
	}
}