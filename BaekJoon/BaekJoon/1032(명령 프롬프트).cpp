#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;										//파일 이름 개수
	string s[50];								//입력할 문자열 -> 이차원배열과 동일	
	//char s[50][50];
	string arr;									//s[0]를 복사해 저장한 후 다른 s들과 비교할 문자열
	int len;									//입력한 문자열 s의 길이

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	len = s[0].length();						//문자열 길이를 len에 저장
	//len = strlen(s[0]);
	arr = s[0];									//문자열 arr에 s[0]를 저장

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (arr[j] != s[i][j])				//s[i][j]가 arr[i]와 다른 경우
				arr[j] = '?';
		}
	}

	cout << arr << endl;

	return 0;
}