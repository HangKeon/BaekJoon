#include <iostream>
using namespace std;

//int a[1001];

int main()
{
	int n, k;								//n = 구할 소수의 범위, k = 2 ~ n까지 범위에서 지워야 할 수의 순서
	int cnt = 0;							//지워진 수의 개수를 저장하기 위한 변수
	int a[1001];

	cin >> n >> k;

	for (int i = 2; i <= n; i++)
		a[i] = i;

	for (int i = 2; i <= n; i++)
	{
		if (a[i] == 0)						//지워진 경우
			continue;

		for (int j = i; j <= n; j += i)
		{
			if (a[j] == 0)					//지워진 경우
				continue;
			else							//지워지지 않은 경우
			{
				a[j] = 0;					//지우고
				cnt++;						//지운 개수를 세기
			}

			if (cnt == k)					//지운 수의 개수 = k 라면
			{
				cout << j << endl;
				break;
			}
		}
	}

	//PrimeNumberSieve(n, k);


	return 0;
}

/*void PrimeNumberSieve(int n, int k)
{
	int cnt = 0;							//지워진 수의 개수를 저장하기 위한 변수

	for (int i = 2; i <= n; i++)
		a[i] = i;

	for (int i = 2; i <= n; i++)
	{
		if (a[i] == 0)						//지워진 경우
			continue;

		for (int j = i; j <= n; j += i)
		{
			if (a[j] == 0)					//지워진 경우
				continue;
			else							//지워지지 않은 경우
			{
				a[j] = 0;					//지우고
				cnt++;						//지운 개수를 세기
			}

			if (cnt == k)					//지운 수의 개수 = k 라면
			{
				cout << j << endl;
				break;
			}
		}
	}
}
*/
