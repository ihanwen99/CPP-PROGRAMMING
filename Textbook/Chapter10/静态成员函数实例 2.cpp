#include<iostream>
using namespace std;

class StaticSample {
private:
	static int obj_count;
	static int obj_living;
public:
	StaticSample() { ++obj_count; ++obj_living; }
	~StaticSample() { --obj_living; }
	static void display() {
		cout << "总对象数: " << obj_count
			<< "\t存活的对象数: " << obj_living << endl;
	}
};

int StaticSample::obj_count = 0;
int StaticSample::obj_living = 0;

int main() {
	StaticSample::display(); //通过类名限定调用成员函数
	StaticSample s1, s2;
	StaticSample::display();
	StaticSample* p1 = new StaticSample, * p2 = new StaticSample;
	s1.display(); //通过对象调用静态成员函数
	delete p1;
	p2->display(); //通过指向对象的指针调用静态成员函数
	delete p2;
	StaticSample::display();
	return 0;

}