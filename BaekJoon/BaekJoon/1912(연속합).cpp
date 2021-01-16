#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];						//dp[n] : 1 ~ n까지의 숫자 중 연속된 숫자의 최대 합

int main()
{
	int n;
	int ans = 0;					//연속된 숫자의 최대합
	int arr[100001];

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	ans = dp[1];

	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		ans = max(dp[i], ans);
	}

	cout << ans << endl;

	return 0;
}