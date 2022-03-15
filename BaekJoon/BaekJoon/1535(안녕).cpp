#include <iostream>
#include<algorithm>
using namespace std;

int dp[21][101];					//dp[사람 번호][잃은 체력]= 현재 기준 기쁨 최대 점수

int main()
{
	int n;							//사람 수
	int ans = 0;					//최대 기쁨 점수
	int L[21];						//소모되는 체력
	int J[21];						//얻는 기쁨

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> L[i];
	
	for (int i = 1; i <= n; i++)
		cin >> J[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (j + L[i] < 100)												//인사 가능한 경우
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + L[i]] + J[i]);	//현재 기쁨 = max(인사 안 했을 때의 기쁨 점수, 인사 했을 때의 기쁨 점수 + 추가 기쁨 점수)
			else															//인사가 불가능한 경우
				dp[i][j] = max(dp[i - 1][j], dp[i][j]);						//현재 기쁨 = max(이전 기쁨, 현재 기쁨)	

			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << endl;

	return 0;
}