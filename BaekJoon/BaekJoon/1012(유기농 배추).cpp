#include <iostream>
#include <cstring>
using namespace std;

int t;					//테스트 케이스 개수
int m, n, k;			//m : 가로 길이, n : 세로 길이, k : 배추 심은 위치의 개수
int x, y;				//배추의 위치
int arr[51][51];		//땅의 크기
int visited[51][51];	//방문 o : 1, 방문x : 0
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y)
{
	int ax, ay;

	visited[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		ax = x + dx[i];
		ay = y + dy[i];

		if (arr[ax][ay] > 0 && !visited[ax][ay])
		{
			if ((ax >= 0 && ax < m) && (ay >= 0 && ay < n))
				dfs(ax, ay);
		}
	}
}

int main()
{
	cin >> t;

	while (t--)
	{
		int cnt = 0;					//최소의 배추흰지렁이 마리 수

		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));

		cin >> m >> n >> k;

		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			arr[x][y] = 1;
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
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