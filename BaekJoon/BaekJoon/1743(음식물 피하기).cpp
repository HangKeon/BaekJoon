#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k;						//n : 행, m : 열, k : 음식물 쓰레기 개수
int r, c;							//좌표
int cnt;							//연결된 개수
int ans = -1;						//cnt 중 가장 큰 값 저장
int arr[101][101];
int visited[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y)
{
	int ax, ay;

	visited[x][y] = 1;
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		ax = x + dx[i];
		ay = y + dy[i];

		if ((ax >= 1 && ax <= n) && (ay >= 1 && ay <= m))
		{
			if (arr[ax][ay] && !visited[ax][ay])
			{
				dfs(ax, ay);
			}
		}
	}

}

int main()
{
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> r >> c;
		arr[r][c] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] && !visited[i][j])
			{
				cnt = 0;
				memset(visited, 0, sizeof(visited));

				dfs(i, j);

				ans = max(ans, cnt);
			}
		}
	}

	cout << ans << endl;

	return 0;
}