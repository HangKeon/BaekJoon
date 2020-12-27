#include <iostream>
#include <cstring>						//memeset를 위해서 사용
using namespace std;

int arr[101][101];						//arr[i][j] : i에서 j로 연결되어 있으면 1, 없으면 0을 저장
int visited[101] = { 0, };				//visited[k] : k를 방문했으면 1, 없으면 0을 저장
int n;									//노드의 개수

void dfs(int i)
{
	for (int j = 1; j <= n; j++)
	{
		if (arr[i][j] && !visited[j])	//arr이 1이고 visited가 0인 경우 -> 즉, 아직 방문하지 않은 경우
		{
			visited[j]++;				//i에서 j를 방문한 것으로 바꾸고
			dfs(j);						//j로 이동
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));	//visited를 한 번 돌고 나면 0으로 초기화
		dfs(i);

		for (int j = 1; j <= n; j++)
		{
			if (visited[j])					//j를 방문한 경우
				arr[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}




	return 0;
}