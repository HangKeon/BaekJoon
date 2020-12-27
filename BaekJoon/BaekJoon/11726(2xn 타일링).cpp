#include <iostream>
using namespace std;

int dp[1001];								//문제에서 최대 1000까지 입력 가능하다고 했기에 이렇게 선언!

int tile(int n)
{
	if (n == 1)								//n이 1인 경우
		return 1;							//1을 반환
	if (n == 2)								//n이 2인 경우
		return 2;							//2를 반환
	if (dp[n] != 0)							//dp에 값이 있는 경우
		return dp[n];						//dp의 값을 반환

	return dp[n] = (tile(n - 1) + tile(n - 2)) % 10007;	//그 이외에 경우 dp에 새로운 값을 저장해 반환 -> 문제에서 1,007의 나머지를 구하라고 함.
}

int main()
{
	int n;									//타일의 가로의 길이

	cin >> n;

	cout << tile(n) << endl;
	
	return 0;
}