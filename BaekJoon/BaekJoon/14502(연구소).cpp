#include <iostream>
#include <algorithm>
#include<queue>
#include <utility>
#include <cstring>
using namespace std;

int n, m;					//가로, 세로
int ans = 0;				//안전 영역의 최대 개수
int arr[9][9];				//0 : 빈칸, 1 : 벽, 2 : 바이러스
int arr2[9][9];				//arr의 값을 복사할 배열 -> 이걸로 벽을 세우는 시뮬레이션을 함
int dx[] = { 1,-1,0,0 };
int dy[] = { 10,0,1,-1 };


void bfs()						//바이러스를 퍼뜨리는 역할 -> 벽을 3개 세운 이후!
{
	int arr3[9][9];
	int ax, ay;

	memcpy(arr3, arr2, sizeof(arr2));

	queue<pair<int, int> > q;

	for (int i = 0; i < n; i++)				//바이러스를 발견하면 그 인덱스를 q에 저장!
		for (int j = 0; j < m; j++)
			if (arr3[i][j] == 2)
				q.push(make_pair(i, j));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			ax = x + dx[i];
			ay = y + dy[i];

			if ((ax >= 0 && ax < n) && (ay >= 0 && ay < m))
			{
				if (arr3[ax][ay] == 0)
				{
					arr3[ax][ay] = 2;
					q.push(make_pair(ax, ay));		//2가 추가되면 다시 q에 추가!
				}
			}
		}
	}

	int cnt = 0;					//안전영역의 개수

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr3[i][j] == 0)
				cnt++;

	ans = max(ans, cnt);
}

void dfs(int cnt)				//dfs(벽을 세운 횟수)
{
	if (cnt == 3)				//탈출조건
	{
		bfs();
		return;
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr2[i][j] == 0)
			{
				arr2[i][j] = 1;
				dfs(cnt + 1);
				arr2[i][j] = 0;
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
			if (arr[i][j] == 0)						//arr이 빈칸인 경우
			{
				memcpy(arr2, arr, sizeof(arr));
				arr2[i][j] = 1;
				dfs(1);
				arr2[i][j] = 0;
			}
		}
	}

	cout << ans << endl;


	return 0;
}