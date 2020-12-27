#include <iostream>
#include <string>
using namespace std;

int r, c;							//행, 열
int ans;							//파이프라인의 최대 개수
int flag;							//가장 오른쪽 열의 도착 여부 -> 도착 : 1, 도착x : 0
string arr[10001];
int visited[10001][501];
int dx[] = { -1,0,1 };
int dy[] = { 1,1,1 };

void dfs(int x, int y)
{
	int ax, ay;

	visited[x][y] = 1;

	if (y == c - 1)					//탈출조건 -> 가장 오른쪽 열에 도착한 경우
	{
		flag = 1;
		ans++;
		return;
	}


	for (int i = 0; i < 3; i++)
	{
		ax = x + dx[i];
		ay = y + dy[i];

		if ((ax >= 0 && ax < r) && (ay >= 0 && ay < c))
		{
			if (arr[ax][ay] == '.' && !visited[ax][ay])
			{
				dfs(ax, ay);

				if (flag)
					return;
			}
		}
	}
}

int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
		cin >> arr[i];

	for (int i = 0; i < r; i++)				//가장 왼쪽 열에서만 시작!
	{
		flag = 0;

		dfs(i, 0);

	}

	cout << ans << endl;


	return 0;
}