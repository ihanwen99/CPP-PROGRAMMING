#include<iostream>
using namespace std;

int main() {
	char c1, c2, c3;
	for (c1 = 'A'; c1 <= 'C'; c1++) {
		for (c2 = 'A'; c2 <= 'C'; c2++) {
			if (c1 == c2)continue;
			else {
				for (c3 = 'A'; c3 <= 'C'; c3++) {
					if (c3 == c1 || c3 == c2) { continue; }
					else { cout << c1 << c2 << c3 << endl; }
				}
			}
		}
	}
}