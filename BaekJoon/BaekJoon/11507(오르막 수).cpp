#include <iostream>
using namespace std;

int dp[1001][10];					//dp[a][b] : a자릿수에 b가 일의 자리에 왔을 때 오르막 수가 될 수 있는 수
									//ex) dp[3][4] = dp[2][0] + dp[2][1] + dp[2][2] + dp[2][3] + dp[2][4]
									//따라서 dp[a][b] = dp[a-1][0 ~ b]까지의 합

int main()
{
	int n;							//자릿수
	int sum = 0;					//dp[n][0~9]까지의 합
	
	cin >> n;

	for (int i = 0; i < 10; i++)	//한 자리 수는 모든 수가 가능!
		dp[1][i] = 1;

	for(int i=2;i<=n;i++)
		for(int j=0;j<10;j++)
			for (int k = j; k < 10; k++)
			{
				dp[i][k] += dp[i - 1][j];
				dp[i][k] %= 10007;
			}

	for (int i = 0; i < 10; i++)
		sum += dp[n][i];

	cout << sum % 10007 << endl;

	return 0;
}