#include <iostream>
using namespace std;

int n;								//n : 로봇 이동 횟수
double result;
double arr[4];						//동서남북 확률을 저장할 배열
int visited[30][30];				//방문o : 1, 방문x : 0
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


void dfs(int x, int y, double r)		//dfs(행, 열, 현재 누적 확률)
{
	int ax, ay;

	if (n == 0)							//탈출조건
	{
		result += r;
		return;
	}

	visited[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		ax = x + dx[i];
		ay = y + dy[i];

		if (!visited[ax][ay])
		{
			n--;

			dfs(ax, ay, r*arr[i]);

			//다른 방향을 탐색하기 전에 전 방향에서 밟았던 칸을
			//다시 밟지 않은 칸으로 표시!
			n++;
			visited[ax][ay] = 0;
		}
	}
}

int main()
{
	int a;

	cin >> n;

	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		arr[i] = a * 0.01;
	}

	dfs(15, 15, 1.0);

	cout.precision(10);
	cout << fixed << result << endl;

	return 0;
}