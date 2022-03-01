#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3];					//모든 집을 칠하는 최소 비용

int main()
{
	int n;							//집의 수
	int arr[1001][3];				//RGB의 비용을 저장
	
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];

	//dp[0]에 arr[0]를 저장 -> 첫번째 집의 비용을 저장
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < n; i++)	
	{
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];	//i번째 집에 R을 칠하는 최소 비용
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];	//i번째 집에 G를 칠하는 최소 비용
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];	//i번째 집에 B를 칠하는 최소 비용
	}

	cout << min({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] }) << endl;

	return 0;
}