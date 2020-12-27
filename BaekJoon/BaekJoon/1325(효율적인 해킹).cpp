#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, m;						//n : 컴퓨터 개수, m : 신뢰 관계 수
int ans = -1;					//가장 많이 해킹할 수 있는 컴퓨터 개수 
vector<int> v[10001];
int visited[10001];				//방문o : 1, 방문x : 0
int cnt[100001];				//해킹할 수 있는 컴퓨터 개수

void dfs(int x, int c)			//dfs(컴퓨터 번호, 해킹을 시작한 컴퓨터 번호)
{
	if (visited[x])
		return;
	
	visited[x] = 1;
	cnt[c]++;

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];

		dfs(y, c);
	}
}

int main()
{
	int a, b;
	
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));

		dfs(i, i);

		ans = max(ans, cnt[i]);					//해킹할 수 있는 컴퓨터 중 가장 많은 개수 찾기
	}

	for (int i = 1; i <= n; i++)
		if (ans == cnt[i])
			cout << i << ' ';

	cout << endl;


	return 0;
}