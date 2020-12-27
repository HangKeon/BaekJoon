#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;							//지도의 크기
int cnt2 = 0;					//집의 수 
vector<int> cnt;				//집의 수를 저장 -> 이것의 크기는 단지 수
string arr[26];
int visited[26][26];			//방문했으면 1, 안 했으면 0
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x,int y)
{
	int ax, ay;

	visited[x][y] = 1;			//방문처리

	for (int i = 0; i < 4; i++)
	{
		ax = x + dx[i];			//상하좌우
		ay = y + dy[i];

		if ((ax >= 0 && ax < n) && (ay >= 0 && ay < n))
		{
			if (arr[ax][ay] == '1' && !visited[ax][ay])
			{
				dfs(ax, ay);
			}
		}
	}
	cnt2++;
}

int main()
{ 

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '1' && !visited[i][j])
			{
				dfs(i, j);

				cnt.push_back(cnt2);
				cnt2 = 0;
			}
		}
	}

	sort(cnt.begin(),cnt.end());

	cout << cnt.size() << endl;

	for (int i = 0; i < cnt.size(); i++)
		cout << cnt[i] << endl;

	return 0;
}