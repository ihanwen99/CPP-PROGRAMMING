#include <iostream> 
#include <string>
using namespace std;


class girl {
	string name;
	int age;
public:
	girl(string n, int d) { name = n;  age = d; }
	friend void disp(girl& x) { //定义
		cout << x.name << " " << x.age << endl;
	}
};

//void disp(girl& x) {
//	cout << x.name << " " << x.age << endl;
//}


int main() {
	girl e("abc", 15);
	disp(e);
	return 0;
}