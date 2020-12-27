#include <iostream>
#include <algorithm>
using namespace std;
//시간초과
int n, k;							//n : 서울을 제외한 도시의 개수,  k : 보낼 수 있는 시간
int money;							//모금액의 최댓값을 저장
int arr[101][4];					//n<=100이고, 순서대로 도보 시간, 도보 모금액, 자전거 시간, 자전거 모금액

void dfs(int idx, int t, int m)		//dfs(경로 개수, 시간, 모금액)
{
	if (t > k)
		return;

	if (idx == n)
	{
		money = max(money, m);

		return;
	}
	
	dfs(idx + 1, t + arr[idx][0], m + arr[idx][1]);
	dfs(idx + 1, t + arr[idx][2], m + arr[idx][3]);

}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[i][j];

	dfs(0, 0, 0);

	cout << money << endl;

	return 0;
}