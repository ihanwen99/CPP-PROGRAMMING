#include<iostream>
using namespace std;

int main(){
	int left, minPos, k, tmp;
	int array[] = { 2, 5, 1, 9, 10, 0, 4, 8, 7, 6 };
	for (left = 0; left < 10; left++){
		minPos = left;
		for (k = left; k < 10; ++k)
			if (array[k] < array[minPos]) minPos = k;
		tmp = array[left]; array[left] = array[minPos];array[minPos] = tmp;
	}
	for (left = 0; left < 10; ++left) cout << array[left] << ' ';
	return 0;
}