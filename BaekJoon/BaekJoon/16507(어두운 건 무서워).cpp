#include <iostream>
using namespace std;

long long dp[1001][1001];					//누적 합

int main()
{
	int r, c, q;							//r,c : 사진의 크기, q : 사진 일부분의 밝기 평균을 알아볼 개수
	int r1, r2, c1, c2;
	int n;									//좌표마다의 밝기값
	long long sum = 0;						//범위의 합
	int cnt;								//범위의 갯수

	cin >> r >> c >> q;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> n;

			dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + n;
		}
	}

	for (int i = 0; i < q; i++)
	{
		cin >> r1 >> c1 >> r2 >> c2;

		sum = 0;

		sum = dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1];
		cnt = (r2 - r1 + 1)*(c2 - c1 + 1);

		cout << sum / cnt << "\n";
	}

	return 0;
}