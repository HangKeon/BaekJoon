#include <iostream>
using namespace std;

int dp[46] = { 0,1 };            //A, B의 개수

int fibo(int x)
{
	if (x <= 1)
		return dp[x];
	else if (dp[x] != 0)         //x >= 2
	{
		return dp[x];
	}
	else
		return dp[x] = fibo(x - 1) + fibo(x - 2);
}

int main()
{
	int k;                        //누른 버튼 수 

	cin >> k;

	fibo(k);

	cout << dp[k - 1] << ' ' << dp[k] << endl;

	return 0;
}