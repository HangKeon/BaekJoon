#include <iostream>
using namespace std;

int main()
{
	int n;								//1~n 사이의 수 중 신기한 수를 찾기 위한 변수
	int tmp;							//임시로 저장할 변수
	int sum = 0;						//숫자들의 각 자리수를 다 더해 저장할 변수
	int cnt = 0;						//신기한 수를 세는 변수

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		tmp = i;
		sum = 0;

		while (tmp != 0)
		{
			sum += tmp % 10;			//일의 자리를 저장
			tmp /= 10;					//일의 자리를 제외하고 다시 저장
		}

		if (i % sum == 0)
			cnt++;
	}

	cout << cnt << endl;


	return 0;
}