#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[101];				//컴퓨터가 서로 연결되었는지 확인할 배열			
int visited[101];				//방문을 확인하는 배열
int cnt = 0;					//1번 컴퓨터를 통해 바이러스가 걸린 컴퓨터의 수

void dfs(int x)
{
	if (visited[x])				//이미 방문한 경우 탈출!
		return;

	visited[x] = 1;				//방문 안한경우 -> 방문처리!

	if(x!=1)					//1번 자기자신을 제외하고 세야하므로 제외!
		cnt++;

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];		//v[x]와 연결된 다른 컴퓨터들

		dfs(y);
	}

}

void bfs(int s)
{
	queue<int> q;				//언급된 컴퓨터들을 순서대로 큐에 저장

	q.push(s);
	visited[s] = 1;				//q에 입력된 s를 방문처리!

	while (!q.empty())			//q가 비어있지 않다면
	{
		int x = q.front();		//q의 제일 앞의 값을 대입

		q.pop();				//q의 제일 앞에 있는 값을 꺼내준다

		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];	//x와 연결된 다른 컴퓨터들을 저장!

			if (!visited[y])	//y가 방문하지 않은 경우
			{
				q.push(y);
				visited[y] = 1;
				cnt++;
			}
		}
	}
}




int main()
{
	int n, m;					//n : 컴퓨터 수, m : 네트워크에 연결된 컴퓨터 쌍 수
	int a, b;					//연결된 컴퓨터 a,b

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	//bfs(1);

	cout << cnt << endl;

	return 0;
}