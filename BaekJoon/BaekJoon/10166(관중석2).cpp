#include <iostream>
using namespace std;

int arr[2001][2001] = { 0, };			//arr[분자][분모] = 존재하면 1, 없으면 0

int gcd(int a, int b)						//최대공약수
{
	int c;

	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main()
{
	int m, n;								//원의 반지름 범위
	int share;								//분모 분자의 최대공약수
	int cnt = 0;							//사용된 좌석의 수

	cin >> m >> n;

	for (int i = m; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			share = gcd(i, j);

			int tmp = arr[j / share][i / share];

			if (tmp==0)							//만약 tmp가 아직 한 번도 사용하지 않은 좌석이라면
			{
				tmp++;								//1을 증가
				cnt++;
			}
		}
	}

	cout << cnt << endl;



	return 0;
}