#include <iostream>
using namespace std;

int Acnt[1000001], Bcnt[1000001];

int main()
{
	int k;                  //손님이 구매하고자 하는 피자 크기
	int n, m;               //A,B 피자조각의 개수
	int sum = 0;            //각 피자조각을 저장
	int ans = 0;            //피자를 판매하는 모든 가짓수
	int A[1001], B[1001];      //A,B의 피자조각을 저장할 배열

	cin >> k >> n >> m;

	Acnt[0] = 1;
	Bcnt[0] = 1;

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		sum += A[i];
	}

	Acnt[sum]++;
	sum = 0;

	for (int i = 0; i < m; i++)
	{
		cin >> B[i];
		sum += B[i];
	}

	Bcnt[sum]++;

	for (int i = 0; i < n; i++)
	{
		sum = 0;

		for (int j = 0; j < n - 1; j++)
		{
			sum += A[(i + j) % n];
			Acnt[sum]++;
		}
	}

	for (int i = 0; i < m; i++)
	{
		sum = 0;

		for (int j = 0; j < m - 1; j++)
		{
			sum += B[(i + j) % m];
			Bcnt[sum]++;
		}
	}

	for (int i = 0; i <= k; i++)
		ans += Acnt[i] * Bcnt[k - i];

	cout << ans << endl;

	return 0;
}