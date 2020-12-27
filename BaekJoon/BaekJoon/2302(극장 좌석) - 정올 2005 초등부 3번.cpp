#include <iostream>
using namespace std;

int dp[41] = { 1,1 };         //dp[n]= k -> n개의 좌석이 있을 때 앉을 수 있는 k가지의 방법
int arr[41];               //고정석의 번호

int main()
{
	int n;                  //좌석의 개수
	int m;                  //고정석의 개수
	int cnt;               //vip가 나오기 전까지의 개수
	int ans = 1;            //주어진 조건을 만족하는 가짓수

	cin >> n >> m;

	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	for (int i = 1; i <= m; i++)
		cin >> arr[i];

	for (int i = 1; i <= m + 1; i++)
	{
		if (i <= m)
			cnt = arr[i] - arr[i - 1] - 1;
		else
			cnt = n - arr[i - 1];

		ans *= dp[cnt];
	}

	cout << ans << endl;

	return 0;
}