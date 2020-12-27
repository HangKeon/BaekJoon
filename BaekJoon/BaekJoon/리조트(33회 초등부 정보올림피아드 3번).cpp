#include <stdio.h>

const int MAXDAY = 100;
int dp[MAXDAY + 1][MAXDAY * 2 + 1];									//dp[휴가일수][쿠폰개수]
int rest[MAXDAY + 1];												//다른 일정으로 리조트에 갈 수 없는 날
int n, m;															//n = 휴가 일수, m = 리조트 갈 수 없는 일수

void upd(int i, int j, int v)
{
	if (i > n)
		return;
	if (dp[i][j] == -1)
		dp[i][j] = v;
	if (dp[i][j] > v)
		dp[i][j] = v;

}

int main()
{
	int x;															// x = 리조트 갈 수 없는 날
	int i, j;

	scanf_s("%d %d", &n, &m);

	for (i = 1; i <= n; i++)
		rest[i] = 1;												//모든 휴가 일수에 1을 대입

	for (i = 0; i < m; i++)
	{
		scanf_s("%d", &x);
		rest[x] = 0;												//리조트 가지 못하는 날에 rest 배열에 0을 대입
	}

	for (i = 0; i <= n; i++)
		for (j = 0; j <= n * 2; j++)
			dp[i][j] = -1;

	dp[0][0] = 0;													//제일 처음 휴가를 시작하기 전은 아무것도 지불하지 않았기에 0을 대입

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i * 2; j++)
		{
			if (dp[i][j] == -1)
				continue;

			if (rest[i + 1] == 0)									//리조트에 갈 수 없는 날일 경우
				upd(i + 1, j, dp[i][j]);

			if (j >= 3)												//쿠폰 개수가 3개 이상인 경우
				upd(i + 1, j - 3, dp[i][j]);

			upd(i + 1, j, dp[i][j] + 10000);									//1일권

			upd(i + 1, j + 1, dp[i][j] + 25000);									//3일권
			upd(i + 2, j + 1, dp[i][j] + 25000);
			upd(i + 3, j + 1, dp[i][j] + 25000);

			upd(i + 1, j + 2, dp[i][j] + 37000);									//5일권
			upd(i + 2, j + 2, dp[i][j] + 37000);
			upd(i + 3, j + 2, dp[i][j] + 37000);
			upd(i + 4, j + 2, dp[i][j] + 37000);
			upd(i + 5, j + 2, dp[i][j] + 37000);

		}
	}

	int ans = dp[n][0];
	for (j = 1; j <= n * 2; j++)
		ans = (ans > dp[n][j]) ? dp[n][j] : ans;

	printf("%d\n", ans);

	return 0;
}