#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3];					//dp[a][b] : 1~a번 집을 RGB 세 가지 색으로 칠하는 비용의 최소합

int main()
{
	int n;							//집의 수
	int arr[1001][3];				//RGB로 칠하는 비용

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];

	for (int i = 0; i < 3; i++)		//1번 집의 RGB 색의 비용을 저장 
		dp[0][i] = arr[0][i];

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];		//i번째 집의 R을 칠하는 최소 비용 
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];		//i번째 집의 G를 칠하는 최소 비용
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];		//i번째 집의 B를 칠하는 최소 비용
	}

	cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;

	return 0;
}