#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;								//건물 종류 수
int arr[501];						//arr[x] : 진입차수를 저장할 배열(즉, x를 하기 위해 선행되어야 하는 정점들의 개수)
int time[501];						//time[x] : 건물 x를 짓는데 걸리는 시간
int dp[501];						//dp[x] : 정점x에 도달할 때까지 걸리는 시간
vector<int> v[501];					//그래프

void topology()
{
	queue<int> q;					//arr 값이 0인 정점(건물 번호)을 저장

	for (int i = 1; i <= n; i++)	//arr이 0인 노드i를 q에 저장
		if (!arr[i])
		{
			q.push(i);
			dp[i] = time[i];		//자기 자신의 시간을 dp에 저장
		}

	for (int i = 1; i <= n; i++)
	{
		int x = q.front();
		q.pop();

		for (int j = 0; j < v[x].size(); j++)
		{
			int y = v[x][j];

			dp[y] = max(dp[y], dp[x] + time[y]);	//max(현 건물 y를 짓는데 걸리는 시간, 건물x를 짓는데 걸린 시간 + y를 짓는데 걸리는 시간)

			if (--arr[y] == 0)
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dp[i] << endl;
}

int main()
{
	int a;							//먼저 지어져야 하는 건물들의 번호

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> time[i];

		while (1)
		{
			cin >> a;

			if (a == -1)
				break;

			v[a].push_back(i);
			arr[i]++;
		}
	}

	topology();

	return 0;
}