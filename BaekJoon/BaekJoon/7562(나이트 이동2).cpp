#include <iostream>
#include <algorithm>
using namespace std;

int n;						//테스트케이스 수
int l;						//체스판 한 변의 길이
int ans = 2e9;
 pair<int, int> s, e;
int visited[301][301];
int dx[] = { 2,2,1,1,-1,-1,-2,-2 };
int dy[] = { 1,-1,2,-2,2,-2,-1,1 };


void dfs(int x, int y, int c)
{
	int ax, ay;

	if (x == s.first&&y == s.second)
	{
		ans = min(ans, c);
		return;
	}

	visited[x][y] = 1;

	for (int i = 0; i < 8; i++)
	{
		ax = x + dx[i];
		ay = y + dy[i];

		if ((ax >= 0 && ax < l) && (ay >= 0 && ay < l))
		{
			if (!visited[ax][ay])
			{
				dfs(ax, ay, c+1);
			}
		}



	}






}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		memset(visited, 0, sizeof(visited));

		cin >> l;
		cin >> s.first >> s.second >> e.first >> e.second;

		dfs(s.first, s.second, 0);

		cout << ans << endl;

		ans = 2e9;
	}



	return 0;
}