#include <iostream>
using namespace std;

int main()
{
	int n;									//입력할 숫자의 개수
	int arr[101] = { 0, };					//입력할 숫자를 저장하는 배열
	long long dp[101][21] = { 0, };			//dp[n의 값][0~20] -> dp[i][j] = i번째 수까지 계산했을 때 j를 만들 수 있는 경우의 수
	int a, b;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1][arr[1]] = 1;						//최초로 입력한 값을 dp에 저장

	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (dp[i][j] > 0)
			{
				a = j + arr[i + 1];
				b = j - arr[i + 1];

				if (a >= 0 && a <= 20)
					dp[i + 1][a] += dp[i][j];

				if (b >= 0 && b <= 20)
					dp[i + 1][b] += dp[i][j];
			}
		}
	}

			cout << dp[n - 1][arr[n]] << endl;





	return 0;
}