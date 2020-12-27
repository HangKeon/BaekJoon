#include <iostream>
#include <cstring>
using namespace std;

int n, m;					//행, 열
int arr[301][301];
int arr2[301][301];			//arr의 복사본 -> 없앤 후 arr에 복사!
int visited[301][301];		//방문o : 1, 방문 x : 0
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y)
{
	int ax, ay;

	visited[x][y] = 1;

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

			if (!arr[ax][ay])		//바다인 경우
			{
				arr2[x][y]--;
			}

			if (arr2[x][y] < 0)		//0으로 바꾸어주기
				arr2[x][y] = 0;
		}
	}
}

int main()
{
	int year = 0;					//2개 이상으로 빙산이 분리되는데 걸리는 연 수
	int cnt = 0;					//빙산의 개수

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			arr2[i][j] = arr[i][j];
		}

	while (1)
	{
		memset(visited, 0, sizeof(visited));
		memcpy(arr, arr2, sizeof(arr2));
		cnt = 0;								//다시 초기화!

		for (int i = 1; i < n - 1; i++)
		{
			for (int j = 1; j < m - 1; j++)
			{
				if (arr[i][j] && !visited[i][j])
				{
					dfs(i, j);
					cnt++;
				}
			}
		}

		//cnt = 1인 경우는 빙산이 1개인 경우이므로 볼 필요x
		if (cnt == 0)
		{
			cout << '0' << endl;
			return 0;
		}
		else if (cnt > 1)
		{
			cout << year << endl;
			return 0;
		}

		year++;
	}

	return 0;
}