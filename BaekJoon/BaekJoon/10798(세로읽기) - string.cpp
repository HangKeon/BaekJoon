#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s[5];					//입력하는 문자열

	for (int i = 0; i < 5; i++)
		cin >> s[i];
	
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 5; j++)
			if (i < s[j].length())		//s[i]의 범위 내에서만 출력
				cout << s[j][i];

	return 0;
}