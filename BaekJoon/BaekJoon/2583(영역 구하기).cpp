#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n, k;					//m : 가로 , n : 세로,  k : 직사각형의 개수
int cnt;						//직사각형의 개수
vector<int> r;					//직사각형의 개수를 저장할 배열
int arr[101][101];				//영역의 크기
int visited[101][101];			//방문o : 1, 방문x : 0
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

		if ((ax >= 0 && ax < m) && (ay >= 0 && ay < n))
		{
			if (arr[ax][ay] == 0 && !visited[ax][ay])
			{
				dfs(ax, ay);
			}
		}
	}
	cnt++;
}

int main()
{
	int x1, y1, x2, y2;

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int a = x1; a < x2; a++)				//직사각형인 부분은 전부 1로 바꾸기
			for (int b = y1; b < y2; b++)
				arr[b][a] = 1;						//주의 : 좌표로 주어졌으므로 배열 취급시 반대로!!
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0 && !visited[i][j])
			{
				dfs(i, j);

				r.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(r.begin(), r.end());

	cout << r.size() << endl;

	for (int i = 0; i < r.size(); i++)
		cout << r[i] << ' ';

	return 0;
}