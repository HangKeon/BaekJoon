#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;					//바이러스에 걸린 컴퓨터 개수
vector<int> v[101];				//그래프
int visited[101];				//방문 처리

void dfs(int x)
{
	if (visited[x]) return;

	visited[x] = 1;

	cnt++;

	for (int i = 0; i < v[x].size(); i++)
		dfs(v[x][i]);
}

int main() 
{
	int n;						//컴퓨터의 수
	int m;						//컴퓨터의 쌍 수 
	
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	cout << cnt - 1 << endl;
}