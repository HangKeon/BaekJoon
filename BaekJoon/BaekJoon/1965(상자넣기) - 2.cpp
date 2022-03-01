#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];					//상자의 개수를 저장

int main()
{
	int n;						//상자의 개수 
	int ans = 0;				//최대 상자의 개수
	int arr[1001];				//상자의 크기

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;				//자기 자신의 개수를 셈

		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);

		ans = max(ans, dp[i]);
	}

	cout << ans << endl;

	return 0;
}