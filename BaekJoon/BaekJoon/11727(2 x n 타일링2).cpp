#include <iostream>
using namespace std;

int dp[1001];					//이미 한 번 나온 값은 더이상 계산하지 않고 배열에 저장

int tile(int x)
{
	if (x == 1)					//n=1인 경우 방법은 1가지
		return 1;
	else if (x == 2)			//n=2인 경우 방법은 3가지
		return 3;
	else if (dp[x] != 0)		//n>=3인 경우 dp[x]가 0이 아니면 그대로 출력(메모이제이션)
		return dp[x];

	return dp[x] = (tile(x - 1) + 2 * tile(x - 2)) % 10007;	//메모이제이션 -> 중복 방지
}

int main()
{
	int n;						//가로의 길이

	cin >> n;

	cout << tile(n) << endl;

	return 0;
}