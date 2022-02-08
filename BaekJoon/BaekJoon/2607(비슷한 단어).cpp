#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n;						//단어의 갯수
	int sw = 0;					//비슷한 단어가 될 수 없는 경우
	int x = 0;					//alp<alp2의 갯수
	int y = 0;					//alp>alp2의 갯수
	int cnt = 0;				//비슷한 단어의 갯수
	string s;					//첫 번째 문자열
	string s2;					//나머지 문자열
	int alp[27] = { 0 };		//문자열 s의 알파벳 갯수를 저장할 배열
	int alp2[27] = { 0 };		//문자열 s2의 알파벳 갯수를 저장할 배열

	cin >> n;
	cin >> s;

	for (int i = 0; i < s.length(); i++)		//s의 알파벳 갯수 구하기
		alp[s[i] - 'A']++;

	n--;										//문자열s의 갯수를 감소

	while (n--)
	{
		cin >> s2;

		//새로운 문자열 입력시 초기화
		memset(alp2, 0, sizeof(alp2));
		sw = 0;
		x = 0;
		y = 0;

		for (int i = 0; i < s2.length(); i++)	//s2의 알파벳 갯수 구하기
			alp2[s2[i] - 'A']++;

		for (int i = 0; i < 26; i++)
		{
			if (alp[i] == alp2[i])				//s와 s2의 알파벳 갯수가 같은 경우
				continue;

			if (abs(alp[i] - alp2[i]) > 1)		//비슷한 단어가 될 수 없는 경우
			{
				sw = 1;
				break;
			}
			else if (alp[i] < alp2[i])			//알파벳 갯수가 차이 나는 경우 x++;
				x++;
			else if (alp[i] > alp2[i])			//알파벳 갯수가 차이 나는 경우 y++;
				y++;

			if (x > 1 || y > 1)					//x 또는 y의 갯수가 2이상인 경우 -> 비슷한 단어 될 수 없다!
			{
				sw = 1;
				break;
			}
		}

		if (sw)									//비슷한 단어가 아니다!
			continue;

		cnt++;

	}

	cout << cnt << endl;

	return 0;
}