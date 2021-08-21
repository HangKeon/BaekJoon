#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001];		//dp[갯수][무게] : 누적합 중 가치의 최댓값

int main()
{
	int n, k;					//n : 물품의 수, k : 버틸 수 있는 무게
	int w[101], v[101];			//w : 물건의 무게, v : 물건의 가치
	
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)		//j : 배낭 무게
			if (j < w[i])					//무게가 초과해 해당 차례의 물건을 담지 않는 경우
				dp[i][j] = dp[i - 1][j];
			else							//해당 차례의 물건을 담는 경우([배낭 무게 - 해당 차례 물건 무게]+해당 차례 물건 가치)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
	}

	cout << dp[n][k] << endl;



	return 0;
}