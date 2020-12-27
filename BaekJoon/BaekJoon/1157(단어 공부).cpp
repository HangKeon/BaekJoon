#include <iostream>
#include <string>
using namespace std;

//A : 65 ~ Z : 90
//a : 97 ~ z : 122

int main()
{
	int alphabet[26] = { 0, };					//알파벳 A~Z까지 저장(아스키코드로)
	string s;									//입력할 문자열
	int MAX = 0;								//가장 많이 사용된 알파벳의 개수를 저장
	char alpha;									//가장 많이 사용된 알파벳을 저장

	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 65 && s[i] <= 90)			//대문자인 경우
			alphabet[s[i] - 65]++;
		else if (s[i] >= 97 && s[i] <= 122)		//소문자인 경우
			alphabet[s[i] - 97]++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (MAX < alphabet[i])					//가장 많이 사용된 알파벳이 한 개인 경우
		{
			MAX = alphabet[i];					//MAX에 alphabet를 저장
			alpha = i + 65;						//alpha에 가장 많이 사용된 알파벳을 대문자로 저장
		}
		else if (MAX == alphabet[i])			//가장 많이 사용된 알파벳이 여러 개인 경우
		{
			alpha = '?';
		}
	}

	cout << alpha << endl;

	return 0;
}