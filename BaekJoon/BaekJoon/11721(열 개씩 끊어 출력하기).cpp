#include <iostream>
using namespace std;

int main()
{
	char str[100];						//문자열을 입력하기 위한 변수, 문자열이 100을 넘지 않기 때문에 배열을 100으로 지정.
	int len = 0;						//입력한 문자열의 길이를 표현하기 위한 변수

	cin >> str;
	len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		cout << str[i];					//입력한 문자열을 출력

		if ((i + 1) % 10 == 0)			//i=0 부터 시작하기 때문.
			cout << "\n";
	}



	return 0;
}

//하