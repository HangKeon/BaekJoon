#include <iostream>
#include <algorithm>
using namespace std;

int dp[301];               //dp[n] : n번 째까지의 계단 누적 점수 최댓값
int arr[301];               //계단의 점수 저장하는 배열

int main()
{
	int n;                  //계단의 갯수

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	//점화식이 통하지 않는 부분
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

	//점화식
	for (int i = 4; i <= n; i++)
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);

	cout << dp[n] << endl;

	return 0;
}