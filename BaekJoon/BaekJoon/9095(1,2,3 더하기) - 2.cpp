#include <iostream>
using namespace std;

int dp[11];

int main()
{
	int t;						//테스트 케이스 수
	int n;						//1,2,3으로 표현하고 싶은 값

	cin >> t;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (t--)
	{
		cin >> n;

		for (int i = 4; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	
		cout << dp[n] << endl;
	}

	return 0;
}