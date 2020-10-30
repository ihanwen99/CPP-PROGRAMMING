#include<iostream>
#include<string>
using namespace std;


void swap(char str[], int k, int i) {
	char tmp = str[k];
	str[k] = str[i];
	str[i] = tmp;
}


void PermuteWithFixedPrefix(char str[], int k) {
	int i;
	if (k == strlen(str)) cout << str << endl;
	else for (i = k; i < strlen(str); ++i){
		swap(str, k, i);
		PermuteWithFixedPrefix(str, k + 1);
		swap(str, k, i);
	}
}

void ListPermutations(char str[]) {
	PermuteWithFixedPrefix(str, 0);
}

int main() {
	char str[] = "ABC";
	ListPermutations(str);
	return 0;
}