#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char arr[6][11];					//입력할 문자열, 최대 글자 10글자, 5문장
	int cnt[6] = { 0, };				//FBI가 있는 요원을 저장
	int c = 0;							//cnt의 개수를 셈, 만약 cnt == 0인 경우 FBI는인 요원이 하나도 없다는 뜻
	int a;								//arr의 문자열의 길이 - 2

	for (int i = 1; i < 6; i++)
		cin >> arr[i];

	for (int i = 1; i < 6; i++)
	{
		a = strlen(arr[i]) - 2;
		for (int j = 0; j < a; j++)
		{
			if (arr[i][j] == 'F'&&arr[i][j + 1] == 'B'&&arr[i][j + 2] == 'I')
			{
				cnt[i] = i;
				c++;
				cout << cnt[i] << ' ';
				break;
			}
		}
	}

	if (c == 0)
		cout << "HE GOT AWAY!";

	cout << endl;

	return 0;
}