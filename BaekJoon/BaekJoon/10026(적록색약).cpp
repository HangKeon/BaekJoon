#include <iostream>
#include <cstring>
using namespace std;

char rgb[101][101];						//RGB를 저장할 배열
int visited[101][101] = { 0, };			//visited[i][j]를 방문한 경우는 1, 방문하지 않은 경우는 0을 출력
int n, cnt = 0;							//n = 개수, cnt = 적록색약이 아닌 사람의 저장할 구역의 수
int cnt2 = 0;							//cnt2 = 적록색약인 사람의 저장할 구역의 수

void dfs(int a, int b)
{
	for (int i = a; i <= n; i++)
	{
		for (int j = b; j <= n; j++)
		{
			if (visited[i][j])			//탈출조건
				return;

			visited[i][j]++;									//자기 자신도 방문한 것이므로 1증가

			if (rgb[i][j] == rgb[i - 1][j] && i >= 2)			//위쪽이 같은 경우
			{
				dfs(i - 1, j);
			}

			if (rgb[i][j] == rgb[i][j + 1] && j < n)			//오른쪽이 같은 경우
			{
				dfs(i, j + 1);
			}

			if (rgb[i][j] == rgb[i][j - 1] && j >= 2)			//왼쪽이 같은 경우
			{
				dfs(i, j - 1);
			}

			if (rgb[i][j] == rgb[i + 1][j] && i < n)			//아래쪽이 같은 경우
			{
				dfs(i + 1, j);
			}

			return;
		}

	}
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> rgb[i][j];


	for (int i = 1; i <= n; i++)					//적록색약이 아닌 사람이 본 경우 구역의 수 구하기
	{
		for (int j = 1; j <= n; j++)
		{
			if (!visited[i][j])
			{
				dfs(i, j);
				cnt++;
			}
		}

	}

	memset(visited, 0, sizeof(visited));		//visited를 0으로 초기화

	for (int i = 1; i <= n; i++)					//R과 G를 같게 바꾸기 -> 적록색약을 위한 과정
	{
		for (int j = 1; j <= n; j++)
		{
			if (rgb[i][j] == 'G')
			{
				rgb[i][j] = 'R';
			}
		}

	}

	for (int i = 1; i <= n; i++)					//적록색약인 사람이 본 구역의 수 구하기
	{
		for (int j = 1; j <= n; j++)
		{
			if (!visited[i][j])
			{
				dfs(i, j);
				cnt2++;
			}
		}

	}

	cout << cnt << ' ' << cnt2 << endl;

	return 0;
}