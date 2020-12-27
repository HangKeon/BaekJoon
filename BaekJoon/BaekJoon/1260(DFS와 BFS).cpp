#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> node[1001];				//각 노드들이 연결된 값을 저장할 이차원 배열
int visited[1001];					//노드들을 방문했는지 확인하는 배열	-> DFS
int visited2[1001];					//노드들을 방문했는지 확인하는 배열 -> BFS

void bfs(int start)
{
	queue<int> q;

	q.push(start);					//큐에 start 값을 넣기

	visited2[start] = 1;				//방문한 것으로 바꾸기

	while (!q.empty())				//q가 비어있지 않은 경우 실행
	{
		int x = q.front();			//큐의 제일 앞의 값을 대입

		q.pop();					//밖으로 내보내기

		cout << x << ' ';

		for (int i = 0; i < node[x].size(); i++)
		{
			int y = node[x][i];

			if (!visited2[y])		//노드 y를 방문을 안했다면
			{
				q.push(y);			//q에 대입
				visited2[y] = 1;		//y를 방문처리
			}
		}

	}
}

void dfs(int x)
{
	if (visited[x])				//start 노드를 이미 방문한 경우 탈출!
		return;

	visited[x] = 1;				//방문을 안 한 경우 -> 방문처리!

	cout << x << ' ';

	for (int i = 0; i < node[x].size(); i++)
	{
		int y = node[x][i];		//노드 x와 연결된 i번째 노드를 저장

		dfs(y);
	}

}

int main()
{
	int n, m, v;					//n : 정점의 개수, m : 간선의 개수, v : 탐색을 시작할 번호
	int x, y;						//연결된 노드 x,y

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;

		node[x].push_back(y);
		node[y].push_back(x);
	}

	for (int i = 1;i<=n;i++)		//node[i]와 연결된 노드들을 오름차순으로 정렬!
	{
		sort(node[i].begin(), node[i].end());
	}

	dfs(v);

	cout << endl;

	bfs(v);

	cout << endl;

	return 0;
}