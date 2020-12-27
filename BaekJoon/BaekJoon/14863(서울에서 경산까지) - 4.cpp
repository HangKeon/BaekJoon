#include <iostream>
using namespace std;

int n, k;									//n = 구간의 개수, k = 최대 시간
int dp[101][100001] = { 0, };				//dp[구간][걸리는 시간] = 모금액
int time[101][2], money[101][2];			//[구간][도보/자전거] -> 걸리는시간, 모금액 두 가지 배열로 나눔

int dfs(int cnt, int t, int m)				//dfs(구간의 개수, 걸리는 누적 시간, 누적 모금액)
{
	if (t > k)								//만약 누적시간 > k 라면 -> 탈출조건
		return -1;							//-1을 반환

	if (cnt == n && t <= k)					//만약 구간 = n 이면서 걸리는 시간 <= k
		return m;							//m을 반환 -> 우리가 구해야 하는 최대 금액

	if (dp[cnt][t] != 0)					//만약 dp가 초기값이 아닌 경우
		return dp[cnt][t] + m;				//dp에 현재 누적 모금액을 더한다.

	int val = -1;
	int temp = dfs(cnt + 1, t + time[cnt + 1][0], m + money[cnt + 1][0]);

	if (val < temp)		//도보의 모금액이 더 큰 경우
		val = temp;

	temp = dfs(cnt + 1, t + time[cnt + 1][1], m + money[cnt + 1][1]);

	if (val < temp)		//자전거의 모금액이 더 큰 경우
		val = temp;

	if (val == -1)
		dp[cnt][t] = -1;
	else
		dp[cnt][t] = val - m;

	return val;
}



int main()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> time[i][0] >> money[i][0] >> time[i][1] >> money[i][1];

	int ans = dfs(1, time[1][0], money[1][0]);							//ans = 구간1~n까지 시작이 도보인 최대 모금액을 저장

	int temp = dfs(1, time[1][1], money[1][1]);

	if (ans < temp)							//만약 asn보다 구간1~n까지의 시작이 자전거인 최대 모금액이 클 경우 
		ans = temp;

	cout << ans << endl;






	return 0;
}