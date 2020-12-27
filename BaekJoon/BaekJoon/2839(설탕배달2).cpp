#include <iostream>
using namespace std;

int main()
{
	int a, b, c;					//a : 입력값, b : a에서 사용할 수 있는 5의 최대 개수, c : 5를 사용하고 남은 a의 무게
	int min = 9999;					//최소값 저장
	int cnt = 0;					//사용된 봉지의 개수

	cin >> a;

	b = a / 5;

	for (int i = 0; i <= b; i++)
	{
		c = a - 5 * i;
		cnt = 0;

		if (c % 3 == 0)
		{
			cnt += c / 3;
			cnt += i;

			if (min > cnt)
				min = cnt;
		}
	}

	if (min == 9999)
		min = -1;

	cout << min << endl;



	return 0;
}