#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;							//삼각형의 크기를 입력할 값
	int dp[501][501] = { 0, };		//dp[삼각형 줄][들어갈 값]
	int max_value = 0;				//dp중 최댓값을 저장
	cin >> n;

	for (int i = 1; i <= n; i++)		//dp를 입력
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> dp[i][j]; 

			if (j == 1)
				dp[i][j] = dp[i - 1][j] + dp[i][j];
			else if (i == j)
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + dp[i][j];

			if (max_value < dp[i][j])
				max_value = dp[i][j];
		}
	}

	cout << max_value << endl;


	return 0;
}