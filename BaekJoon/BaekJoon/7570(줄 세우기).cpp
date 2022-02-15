#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];				//연속된 LIS의 갯수를 저장

int main()
{
	int n;						//아이들의 수
	int a;						//아이들 번호
	int ans = 0;				//최대 LIS의 크기
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;

		dp[a] = dp[a - 1] + 1;	//a보다 앞에 있는 dp의 갯수 + 1

		ans = max(ans, dp[a]);
	}

	cout << n - ans << endl;

	return 0;
}