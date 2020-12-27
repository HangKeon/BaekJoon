#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001];		//dp[i][j] : i구간을 j분 안으로 지났을 때의 얻을 수 있는 최대 금액

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;				//n : 서울을 제외한 도시의 개수, k : 여행을 보낼 수 있는 시간
	int a, b, c, d;			//a : 도보 시간, b : 도보 모금액, c : 자전거 시간, d : 자전거 모금액
	int ans = 0;			//시간 내의 최대 모금액

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c >> d;

		if (i == 0)							//제일 처음 금액을 이용해 dp값을 설정
		{
			dp[i][a] = b;					//도보 시간이 a일 때 걸리는 도보 모금액
			dp[i][c] = max(dp[i][c], d);	//a == c를 대비해 max를 사용! 평상시는 무조건 d이다!
		}
		else								//첫 번째 도시 이후
		{
			for (int j = 0; j <= k; j++)	//시간초과가 아님!(100 * 100,000 = 10,000,000번), 1초 = 1억번
			{
				if (!dp[i - 1][j])			
					continue;

				if (j + a <= k)				//i지점에서 걸리는 도보 시간
					dp[i][j + a] = max(dp[i][j + a], dp[i - 1][j] + b);

				if (j + c <= k)				//i지점에서 걸리는 자전거 시간
					dp[i][j + c] = max(dp[i][j + c], dp[i - 1][j] + d);
			}
		}
	}

	for (int i = 0; i <= k; i++)
		ans = max(ans, dp[n - 1][i]);

	cout << ans << endl;

	return 0;
}