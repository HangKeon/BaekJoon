#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;							//수열의 크기
	int ans = 0;					//LIS의 최대 길이
	int arr[1001];					//수열
	int dp[1001];					//LIS의 개수

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		dp[i] = arr[i];					//자기 자신의 값 

		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];

		ans = max(ans, dp[i]);
	}

	cout << ans << endl;

	return 0;
}