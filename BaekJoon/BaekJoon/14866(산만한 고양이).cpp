#include <iostream>
#include <vector>
using namespace std;

int n, m;						//n : 방의수, m : 복도의 수
int a, b;						//서로 다른 방의 번호
vector<int> v[300001];			//복도로 연결된 서로 다른 두 방의 번호를 저장할 배열
vector<int> v2[300001];
int visited[300001];
int fu[300001];					//full : i를 루트로 하는 서브트리에 완전히 포함된 back edge 개수
int su[300001];					//sub : i를 루트로 하는 서브트리에 조금이라도 포함된 back edge 개수
int ab[300001];					//absolute : i의 부모와 연결된 back edge 개수


void dfs(int x, int y)			//dfs(현재 노드, 이전 노드)
{
	for (auto i : v[x])
	{
		if (i == y)								//방금 방문한 노드인 경우 -> 건너뜀
			continue;

		if (!visited[i])						//tree edge
		{
			v2[x].push_back(i);
			visited[i] = visited[x] + 1;
			int t = fu[x];

			dfs(i, x);

			ab[i] = fu[x] - t;

			fu[x] += fu[i];
			su[x] += su[i];
		}
		else if (visited[i] < visited[x])		//back edge -> 사이클 발생
		{
			fu[i]++;
			su[x]++;
		}
	}
}

int main()
{
	long long ans = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	visited[1] = 1;
	dfs(1, -1);

	for (int i = 1; i <= n; i++)
	{
		int t = 1;

		for (auto j : v2[i])
		{
			//i의 부모보다 위로 이어지는 간선이 2개 이상인 경우 정점을 제거하면 tree edge와 back edge 모두 생성됨
			//fu[j]가 0이 아니라면 서브트리 내부에 사이클 존재
			if (su[j] - ab[j] > 1 || fu[j])
				t = 0;
		}

		//0이 아니라면 i가 관여를 안 하는 곳에 back edge가 존재
		if (m - n + 1 - su[i])
			t = 0;

		if (t)
			ans += i;
	}

	cout << ans << endl;

	return 0;
}