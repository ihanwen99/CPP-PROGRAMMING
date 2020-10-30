#include<iostream>
#include<string>
using namespace std;


char* subString(char* s, int start, int end) {
	int len = strlen(s);
	if (start < 0 || start >= len || end < 0 || end >= len || start > end)
	{
		cout << "起始或终止位置错" << endl;
		return NULL;
	}
	char* sub = new char[end - start + 2];
	strncpy(sub, s + start, end - start + 1);
	sub[end - start + 1] = '\0';
	return sub; //合法
}

