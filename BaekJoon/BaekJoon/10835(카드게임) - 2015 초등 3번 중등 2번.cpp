#include <iostream>
#include <algorithm>
using namespace std;

int A[2001], B[2001], dp[2001][2001];	//A : 왼쪽 카드의 값을 저장, B : 오른쪽 카드의 값을 저장
										//dp[남은 왼쪽 카드 수][남은 오른쪽 카드수] : 최대값을 저장 -> 0인경우는 방문x!

int card(int a, int b)					//card(주어진 왼쪽 카드 수, 주어진 오른쪽 카드 수)
{
	if (a == 0 || b == 0)				//카드의 수가 0이 되면 끝낸다
		return 0;

	if (dp[a][b] != 0)					//dp가 0이 아니라면 -> 즉, 이미 방문했다면
		return dp[a][b];				//현재 dp를 반환

	dp[a][b] = max(card(a - 1, b), card(a - 1, b - 1));	//왼쪽만 뺀 경우 와 모두 뺀 경우 중 최대값을 저장!

	if (A[a] > B[b])					//왼쪽 카드의 값 > 오른쪽 카드의 값 
		dp[a][b] = max(dp[a][b], card(a, b - 1) + B[b]);	//조건(1)을 비교한 dp와 오른쪽 카드를 한 장 빼고 점수를 얻은 것 중 최대값을 dp에 저장!

	return dp[a][b];

}

int main()
{
	int n;							//한 더미의 카드 개수

	cin >> n;

	for (int i = 1; i <= n; i++)		//주어진 카드 수를 헷갈리지 않도록 인덱스를 1부터 넣는다.
		cin >> A[i];

	for (int i = 1; i <= n; i++)
		cin >> B[i];

	int ans = card(n, n);

	cout << ans << endl;

	return 0;
}