#include <iostream>
using namespace std;

int main()
{
	int n, m, k;						//n:행, m:열, k: o로 표시된 칸의 번호
	int dp[16][16] = { 0, };			//dp[i][j]에 도달하기 위한 경로의 수를 저장
	int midx, midy;						//k의 위치를 찾을 변수
	int cnt = 0;						//k와 같아지는 위치를 찾음
	int value;							//dp[midx][midy]를 저장할 변수 -> 왜냐하면 다음 값을 구할 때 dp[midx][midy]를 1로 초기화해야 하기 때문.


	cin >> n >> m >> k;

	dp[1][1] = 1;

	if (k != 0)							//o가 표시된 칸이 있는 경우
	{
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cnt++;

				if (cnt == k)			//k의 x,y의 값을 저장
				{
					midx = i;			
					midy = j;
				}
			}
		}

		for (int i = 1; i <= midx; i++)		//dp[1][1]부터 k의 위치 dp[midx][midy]까지의 경로의 수를 찾는다.
		{
			for (int j = 1; j <= midy; j++)
			{
				if (i == 1 && j == 1)		//이미 값을 1로 초기화 했으므로 건너뛰어야 한다.
					continue;

				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		value = dp[midx][midy];

		dp[midx][midy] = 1;					//k의 위치의 값을 1로 초기화

		for (int i = midx; i <= n; i++)
		{
			for (int j = midy; j <= m; j++)
			{
				if (i == midx && j == midy)		//이미 값을 1로 초기화 했으므로 건너뛰어야 한다.
					continue;

				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		value *= dp[n][m];

		cout << value << endl;
	}
	else								//o가 표시된 칸이 없는 경우
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (i == 1 && j == 1)	//dp[1][1]=1로 초기화 했으므로 볼 필요가 없다
					continue;

				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}

		cout << dp[n][m] << endl;
	}

	return 0;
}



