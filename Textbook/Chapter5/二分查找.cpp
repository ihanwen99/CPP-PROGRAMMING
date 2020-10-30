#include<iostream>
using namespace std;

int main() {
	int lh = 0, rh = 9, mid, x = 4;
	int array[] = { 0,1,2,3,4,5,6,7,8,9 };
	while (lh <= rh) {
		mid = (lh + rh) / 2;
		if (x == array[mid]) {
			cout << x << " 的位置是: " << mid << endl; break;
		}
		if (x < array[mid]) {
			rh = mid - 1;
		}
		else { lh = mid + 1; }
	}
	if (lh > rh) { cout << "没有找到" << endl; }
	return 0;
}