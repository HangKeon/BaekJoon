#include <iostream>
using namespace std;

int main()
{
	int n, k;									//n = 동전 종류의 개수, k = 동전들로 만들고 싶은 액수
	int a[101] = { 0, };						//동전의 값을 집어넣을 배열
	int dp[101][10001] = { 0, };				//dp[i][j] = i번째 동전까지 사용해 j원을 만드는 경우

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)				//i번째 동전까지 이용해 0원을 만드는 경우는
		dp[i][0] = 1;							//무조건 한 가지이다.

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j >= a[i])
				dp[i][j] = dp[i - 1][j] + dp[i][j - a[i]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k] << endl;
	



	return 0;
}