#include <iostream>
#include <cstring>
using namespace std;

int dp[31][31];						//dp[n][m] : n개의 사이트에서 m개의 사이트로 잇는 다리의 개수
									//ex) dp[2][4] = dp[1][1] + dp[1][2] + dp[1][3]

int main()
{
	int t;							//테스트 케이스 수
	int n, m;						//서쪽(n)과 동쪽(m)에 있는 사이트의 개수 

	cin >> t;

	for (int i = 1; i < 31; i++)	//n=1인 경우는 m의 개수만큼 다리를 만들 수 있음
		dp[1][i] = i;

	for (int i = 2; i < 31; i++)
		for (int j = i; j < 31; j++)
			for (int k = j - 1; k >= i - 1; k--)
				dp[i][j] += dp[i - 1][k];

	while (t--)
	{
		cin >> n >> m;

		cout << dp[n][m] << endl;
	}



	return 0;
}