#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][1001];				//미로
int dp[1001][1001];					//사탕의 최대 누적 개수

int main()
{
	int n, m;						//미로의 크기
	int ans = 0;					

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = max({ dp[i - 1][j - 1],dp[i - 1][j],dp[i][j - 1] }) + arr[i][j];

	cout << dp[n][m] << endl;

	return 0;
}