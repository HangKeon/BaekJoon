#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;							//행과 열의 개수
int arr[101][101];				//어떤 지역의 높이를 나타내는 배열
int visited[101][101];			//방문 여부를 확인!
int dx[] = { 0,0,1,-1 };		//우좌하상
int dy[] = { 1,-1,0,0 };


void dfs(int x,int y, int h)	//dfs(x값, y값, 물의 높이)
{
	int ax, ay;					//인덱스 x,y를 기준으로 dx,dy만큼 움직인 인덱스 값

	visited[x][y] = 1;			//dfs가 적용된 것은 무조건 arr > h이므로 1로 바꿔준다.

	for (int i = 0; i < 4; i++)
	{
		ax = x + dx[i];
		ay = y + dy[i];

		if ((ax >= 0 && ax < n) && (ay >= 0 && ay < n))		//범위 : 0 <= ax < n, 0 <= ay < n
		{
			if (arr[ax][ay] > h && !visited[ax][ay])	//물에 안 잠기면서 방문을 안했다면
			{
				dfs(ax, ay, h);
			}
		}
	}
}

int main()
{
	int Max = 0, Min = 101;			//Max : arr의 최대 높이, Min : arr의 최소 높이
	int cnt = 0;				//안전한 영역의 개수 -> 만약 비에 잠기는 영역이 없는 경우는 안전영역은 1이다.
	int cmp = 1;				//Min ~ Max 사이의 안전 영역의 최대 갯수를 비교힐 값

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			Max = max(Max, arr[i][j]);
			Min = min(Min, arr[i][j]);
		}

	for (int i = Min; i < Max; i++)
	{
		memset(visited, 0, sizeof(visited));
		cnt = 0;

		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < n; b++)
			{
				if (arr[a][b] > i && !visited[a][b])	//안전 영역이면서 방문하지 않은 경우
				{
					dfs(a, b, i);
					cnt++;
				}
			}
		}
		
		cmp = max(cmp, cnt);
	}

	cout << cmp << endl;



	return 0;
}