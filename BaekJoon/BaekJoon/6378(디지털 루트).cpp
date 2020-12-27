#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;								//자리수가 1000자리이므로 문자열로 입력받아야 한다.

	while (1)
	{
		int sum = 0;						//자리수를 더할 변수
		cin >> s;

		if (s == "0")						//0인 경우 탈출
			break;

		for (int i = 0; i < s.length(); i++)
			sum += s[i] - '0';				//입력받은 수의 자리수를 더함

		while (sum > 9)						//sum이 10이상인 경우
		{
			int sum2 = sum;					//sum2에 sum의 값을 대입
			sum = 0;						//sum을 0으로 초기화
			while (sum2 != 0)				//sum2가 0이 아니면
			{
				sum += sum2 % 10;			//sum2의 각각의 자리수를 sum에 더함
				sum2 /= 10;					//대입한 자리수는  제거
			}
		}
		cout << sum << endl;
	}

	return 0;
}