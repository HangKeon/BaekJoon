#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

int n;						//노드의 개수
int a, b, c;				//a,b : 두 노드, c: 거리
int m;						//거리를 알고 싶은 노드의 한 쌍의 개수
int ans = 10001;					//구하려는 값의 최소거리
vector<pair<int, int> > v[40001];
int visited[40001];

//틀린코드 -> lca를 이용해 풀어야 한다.


void dfs(int s, int e, int sum)
{
	if (s == e)
	{
		ans = min(ans, sum);
		return;
	}

	visited[s] = 1;

	for (int i = 0; i < v[s].size(); i++)
	{
		if (!visited[v[s][i].first])
		{
			dfs(v[s][i].first, e, sum + v[s][i].second);
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		memset(visited, 0, sizeof(visited));
		ans = 10001;

		cin >> a >> b;

		if (!visited[a])
		{
			dfs(a, b, 0);
		}

		cout << ans << endl;
	}

	return 0;
}