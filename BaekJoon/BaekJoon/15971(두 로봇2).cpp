#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n, x, y;			//n : 동굴 방의 개수, x,y : 두 로봇이 위치한 방의 번호
int a, b, c;			//c : 통로의 길이
vector<pair<int, int> > v[100001];
int visited[100001];	//1 : 방문o , 0 : 방문x

void dfs(int node, int sum, int m)	//dfs(노드 번호, 통로의 전체 길이 합, 통로 길이 중 가장 긴 간선)
{
	if (node == y)					//탈출조건
	{
		cout << sum - m << endl;
		return;
	}


	visited[node] = 1;				//방문처리

	for(auto i:v[node])
		if (!visited[i.first])
		{
			dfs(i.first, sum + i.second, max(m,i.second));
		}
}

int main()
{
	cin >> n >> x >> y;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	dfs(x, 0, 0);

	return 0;
}