#include <iostream>
using namespace std;

int main()
{
	int n, t, c;					//n = 1,2,3의 조합으로 만들 수, t = 테스트 케이스의 개수, c = t를 복사하기 위한 값
	int dp[11] = { 0, };			//n이 1,2,3으로 만들 수 있는 가짓수를 나타낼 배열
	int dk[11] = { 0, };

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	cin >> t;
	c = t;

	while(t--)
	{
		for (int i = 4; i < 11; i++)	//4~10까지의 dp배열의 갯수를 구하는 식
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

		cin >> n;

		dk[t+1] = dp[n];
	}
	for (int i = c; i > 0; i--)
		cout << dk[i] << endl;

	return 0;
}