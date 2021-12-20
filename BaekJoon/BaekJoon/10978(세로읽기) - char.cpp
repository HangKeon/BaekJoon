#include <iostream>
using namespace std;

//char s[5][16];				//여기에 선언하면 아무 문제도 없음

int main()
{
	char s[5][16] = {' ',};		//여기에 선언하면 전부 빈 공백으로 만들어 주기!

	for (int i = 0; i < 5; i++)
		cin >> s[i];

	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 5; j++)
			if (s[j][i] == NULL)
				continue;
			else
				cout << s[j][i];

	return 0;
}