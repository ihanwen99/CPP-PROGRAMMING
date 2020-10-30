#include<iostream>
#include<string>
using namespace std;

int main()
{
	char sentence[80], prev = ' ';//prev表示当前字符的前一字符
	int i, num = 0;
	gets_s(sentence);
	for (i = 0; sentence[i] != '\0'; ++i) {
		if (prev == ' ' && sentence[i] != ' ')++num;
		prev = sentence[i];
	}
	cout << "单词个数为：" << num << endl;
	return 0;
}