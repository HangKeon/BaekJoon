#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[501][501];
int visited[501][501];
int cnt = 0;			//그림 개수
int sum = 0;			//그림의 넓이
int ans = 0;			//가장 넓은 그림의 넓이
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y)
{
	int ax, ay;

	visited[x][y] = 1;
	sum++;

	for (int i = 0; i < 4; i++)
	{
		ax = x + dx[i];
		ay = y + dy[i];

		if ((ax >= 0 && ax < n) && (ay >= 0 && ay < m))
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
	

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] && !visited[i][j])
			{
				dfs(i, j);
				cnt++;

				ans = max(ans, sum);
				sum = 0;
			}
		}
	}

	cout << cnt << endl << ans << endl;



	return 0;
}