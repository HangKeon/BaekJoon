#include <iostream>
#include <vector>
using namespace std;

int n, m, x;									// n : 학생 수, m : 질문 횟수, x : 학생 번호
int a, b;										// a가 b보다 더 잘했다.
int u, v;										// u : 가능한 가장 높은 등수, v : 가능한 가장 낮은 등수

vector<int> v1[100001];							//자신보다 등수가 낮은 친구들을 기록
vector<int> v2[100001];							//자신보다 등수가 높은 친구들을 기록

int visited[100001];							//자신보다 등수가 낮은 친구들의 수를 기록
int visited2[100001];							//자신보다 등수가 높은 친구들의 수를 기록

int cnt = 0;
int cnt2 = 0;

void dfs1(int node)								//dfs1(노드 번호)
{
	visited[node] = 1;

	for (int i = 0; i < v1[node].size(); i++)
	{
		int k = v1[node][i];

		if (!visited[k])
		{
			dfs1(k);
			cnt++;
		}
	}
}

void dfs2(int node)								//dfs2(노드 번호)
{
	visited2[node] = 1;

	for (int i = 0; i < v2[node].size(); i++)
	{
		int k = v2[node][i];

		if (!visited2[k])
		{
			dfs2(k);
			cnt2++;
		}
	}
}


int main()
{
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		
		v1[a].push_back(b);						//잘하는 친구로 그래프 만들기
		v2[b].push_back(a);						//못하는 친구로 그래프 만들기
	}

	dfs1(x);
	dfs2(x);

	v = n - cnt;							//나보다 성적이 낮은 친구들 수를 제외한 등수
	u = 1 + cnt2;							//나보다 성적이 높은 친구들 수를 제외한 등수

	cout << u << ' ' << v << endl;

	return 0;
}