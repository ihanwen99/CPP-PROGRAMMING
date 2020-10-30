#include<iostream>
using namespace std;

int main() {
	int idx, x=5;
	int array[] = { 2,3,1,7,5,8,9,0,4,6 };
	for (idx = 0; idx < 10; idx++) {
		if (x == array[idx]) { cout << idx; break; }
	}
	if (idx == 10) { cout << "Not Found!" << endl; }
	return 0;
}