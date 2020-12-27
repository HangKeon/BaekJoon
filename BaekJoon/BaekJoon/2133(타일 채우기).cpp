#include <iostream>
using namespace std;

int dp[31];//이미 한 번 나온 값은 더이상 계산하지 않고 배열에 저장

int tile(int x)
{
	if (x == 0)					//n=0인 경우 방법은 1가지
		return 1;
	else if (x == 1)			//n=1인 경우 방법은 0가지
		return 0;
	else if (x == 2)			//n=2인 경우 방법은 3가지
		return 3;
	else if (dp[x] != 0)		//한 번이라도 dp값을 구한적이 있다면 그대로 출력
		return dp[x];

	int ans = 3 * tile(x - 2);	//기본식

	for (int i = 3; i <= x; i++)	//x가 짝수인 값들은 2개씩 존재
		if (i % 2 == 0)
			ans += 2 * tile(x - i);

	return dp[x] = ans;
}

int main()
{
	int n;						//가로의 크기

	cin >> n;

	cout << tile(n) << endl;

	return 0;
}