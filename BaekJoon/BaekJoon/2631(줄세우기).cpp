#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;						//아이들의 수
	int ans = 0;				//최대 LIS의 크기
	int arr[201];				//아이들의 번호
	int dp[201];				//LIS의 갯수를 저장

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;						//자기 자신의 개수를 세줌

		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}

		ans = max(ans, dp[i]);
	}

	cout << n - ans << endl;

	return 0;
}