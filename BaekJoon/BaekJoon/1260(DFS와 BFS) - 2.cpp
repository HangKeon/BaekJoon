#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> vec[1001];
queue<int> q;
int visited[1001];
int visited2[1001];

void dfs(int x)
{
	if (visited[x]) return;

	visited[x] = 1;

	cout << x << ' ';

	for (int i = 0; i < vec[x].size();i++)
		dfs(vec[x][i]);
}

void bfs(int x)
{
	q.push(x);

	visited2[x] = 1;

	while (!q.empty())
	{
		int y = q.front();

		q.pop();

		cout << y << ' ';

		for (int i = 0; i < vec[y].size(); i++)
		{
			int a = vec[y][i];

			if (!visited2[a])
			{
				q.push(a);

				visited2[a] = 1;
			}
		}
	}
}

int main()
{
	int n, m, v;

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;

		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		sort(vec[i].begin(), vec[i].end());

	dfs(v);
	cout << endl;
	bfs(v);
	cout << endl;



	return 0;
}