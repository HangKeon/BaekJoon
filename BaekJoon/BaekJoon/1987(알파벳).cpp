#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int r, c;						//r : 세로(행), c: 가로(열)
int cnt;						//말이 지날 수 있는 최대 칸 개수
int ans = -1;					//cnt와 비교하여 가장 큰 값을 저장
string arr[21];
int alp[26];					//알파벳을 숫자로 저장할 배열
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y)
{
	int ax, ay;

	alp[arr[x][y] - 'A'] = 1;		//알파벳 사용 처리
	cnt++;

	ans = max(cnt, ans);

	for (int i = 0; i < 4; i++)
	{
		ax = x + dx[i];
		ay = y + dy[i];

		if ((ax >= 0 && ax < r) && (ay >= 0 && ay < c))
		{
			if (!alp[arr[ax][ay] - 'A'])
			{
				dfs(ax, ay);
				alp[arr[ax][ay] - 'A'] = 0;				//새롭게 길을 가는 경우 방문 안 한 것으로 처리!
				cnt--;									//방문 안 한 것으로 처리 -> 횟수를 1 감소!
			}
		}
	}
}

int main()
{

	cin >> r >> c;

	for (int i = 0; i < r; i++)
		cin >> arr[i];

	dfs(0, 0);

	cout << ans << endl;

	return 0;
}