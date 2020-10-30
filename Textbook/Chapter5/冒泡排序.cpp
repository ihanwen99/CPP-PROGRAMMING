#include<iostream>
using namespace std;

int main() {
	int arr[] = { 0, 3, 5, 1, 8, 7, 9, 4, 2, 10, 6 };
	int n = 11;

	bool flag = false;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (arr[j - 1] > arr[j]) {
				int tmp = arr[j]; arr[j] = arr[j - 1]; arr[j - 1] = tmp;
				flag = true;
			}
		}
		if (!flag) { break; }
	}

	for (int i = 0; i < n; i++) { cout << arr[i] << ' '; }
	return 0;
}