#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;								//수행해야 할 작업의 수
int ans = 0;						//모든 작업을 완료하기 위한 최소 시간
int arr[10001];						//위상정렬(즉, 선행되어야 할 개수)
int time[10001];					//작업마다 걸리는 시간
int dp[10001];						//선행되는 작업마다 걸리는 시간의 최대값(왜냐하면 모든 작업이 다 끝나야 하므로)
vector<int> v[10001];				//v[b] = i : b -> i 인 그래프

void topology()
{
	queue<int> q;					//선행작업이 없는 값을 저장
	
	for (int i = 1; i <= n; i++)
		if (!arr[i])
			q.push(i);

	for (int i = 1; i <= n; i++)
	{
		int x = q.front();
		q.pop();

		for (int j = 0; j < v[x].size(); j++)
		{
			int y = v[x][j];

			dp[y] = max(dp[y], dp[x] + time[y]);	//모든 작업이 다 끝나야 하므로 최대값 저장

			if (--arr[y == 0])
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++)					//모든 작업이 끝나기 위해서 최대값 찾기
		ans = max(ans, dp[i]);

	cout << ans << endl;
}

int main()
{
	int a;							//그 다음에 그 작업에 대해 선행 관계에 있는 작업들의 개수
	int b;							//선행되어야 하는 작업 번호

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> time[i] >> a;

		dp[i] = time[i];			//자기 자신의 작업마다 걸리는 시간을 저장

		for (int j = 0; j < a; j++)
		{
			cin >> b;

			v[b].push_back(i);		//b -> i인 그래프 작성
		}
	}

	topology();

	return 0;
}