#include <iostream>
#include <vector>
using namespace std;

int n, m;						//n : 사람의 수, m : 친구 관계 수
int a, b;
int sw;							//sw = 1일 때 dfs 정지!
int cnt;
vector<int> v[2001];
int visited[2001];

void dfs(int x, int c)			//dfs(노드 번호, 친구 관계 수)
{
	if (c == 4)					//탈출조건
	{
		sw = 1;
		return;
	}

	visited[x] = 1;

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];

		if (!visited[y])
		{
			dfs(y, c + 1);
		}
	}

	visited[x] = 0;					//미방문처리
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		dfs(i, 0);

		if (sw)
		{
			cout << '1' << endl;
			return 0;
		}
	}

	cout << '0' << endl;

	return 0;
}