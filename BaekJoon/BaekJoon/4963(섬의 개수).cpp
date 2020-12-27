#include <iostream>
#include <cstring>
using namespace std;

int w, h;					//w : 너비, h : 높이
int arr[51][51];			//영역
int visited[51][51];		//방문o : 1, 방문x : 0
int dx[] = { 1,-1,0,0,1,1,-1,-1 };
int dy[] = { 0,0,1,-1,1,-1,1,-1 };

void dfs(int x, int y)
{
	int ax, ay;

	visited[x][y] = 1;

	for (int i = 0; i < 8; i++)
	{
		ax = x + dx[i];
		ay = y + dy[i];

		if ((ax >= 0 && ax < h) && (ay >= 0 && ay < w))
		{
			if (arr[ax][ay] > 0 && !visited[ax][ay])
			{
				dfs(ax, ay);
			}
		}
	}
}

int main()
{
	int cnt = 0;
	
	while (1)
	{
		cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));

		cin >> w >> h;

		if (w == 0 && h == 0)				//탈출조건
			break;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> arr[i][j];

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j] > 0 && !visited[i][j])
				{
					dfs(i, j);

					cnt++;
				}
			}
		}

		cout << cnt << endl;
	}
	

	return 0;
}