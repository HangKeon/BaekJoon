#include <iostream>
using namespace std;

//int dp[1000001];
long long dp[2][1000001];				//dp[0][] : 기본식 저장
										//dp[1][] :	n>=3부터는 무조건 2가지씩 존재하는 값을 저장
long long tile(int x)
{
	//if (x == 0)					//n=0인 경우는 1가지
	//	return 1;
	//else if (x == 1)			//n=1인 경우 2가지
	//	return 2;
	//else if (x == 2)			//n=2인 경우 7가지
	//	return 7;
	//else if (dp[x] != 0)		//한 번이라도 계산된 경우
	//	return dp[x];

	//long long ans = 2 * tile(x - 1) + 3 * tile(x - 2);	//기본식

	//for (int i = 3; i <= x; i++)	//n>=3부터는 무조건 2가지씩 존재
	//	ans += 2 * tile(x - i) % 1000000007;

	//return dp[x] = ans % 1000000007;

	dp[0][0] = 0;
	dp[0][1] = 2;
	dp[0][2] = 7;
	dp[1][2] = 1;
	
	for (int i = 3; i <= x; i++)
	{
		dp[1][i]=(dp[1][i-1]+dp[0][i-3]) % 1000000007;
		dp[0][i]=(2*dp[0][i-1]+3*dp[0][i-2]+2*dp[1][i]) % 1000000007;
	}

	return dp[0][x];

}

int main()
{
	int n;						//가로의 길이

	cin >> n;

	cout << tile(n) << endl;

	return 0;
}