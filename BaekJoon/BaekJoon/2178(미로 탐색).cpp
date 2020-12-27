#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m;					//n : 행, m : 열
string s[101];
int arr[101][101];			//s배열이 방문하는 순서를 확인할 배열
int visited[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs(int x, int y)
{
	int ax, ay;

	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	visited[x][y] = 1;

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			ax = a + dx[i];
			ay = b + dy[i];
			
			if ((ax >= 0 && ax < n) && (ay >= 0 && ay < m))
			{
				if (s[ax][ay] == '1' && !visited[ax][ay] && !arr[ax][ay])
				{
					arr[ax][ay] = arr[a][b] + 1;
					visited[ax][ay] = 1;
					q.push(make_pair(ax, ay));
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> s[i];

	bfs(0, 0);

	cout << arr[n - 1][m - 1] + 1 << endl;

	return 0;
}