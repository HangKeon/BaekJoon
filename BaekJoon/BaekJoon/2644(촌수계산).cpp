#include <iostream>
#include <vector>
using namespace std;

int cnt;						//촌수
int sw = 0;						//0 : 촌수가 없음, 1 : 촌수 존재
vector<int> v[101];
int visited[101];

void dfs(int x, int y)			//dfs(시작, 도착)
{
	if (x == y)					//찾은 경우
	{
		cout << cnt << endl;
		sw = 1;
		return;
	}

	if (visited[x]) return;

	visited[x] = 1;

	for (int i = 0; i < v[x].size(); i++)
	{
		cnt++;
		dfs(v[x][i], y);
		cnt--;
	}
}

int main()
{
	int n, a, b, m;				//n : 전체 사람 수, a,b : 촌수를 계산해야 하는 사람, m : 부모 자식 관계 개수

	cin >> n >> a >> b >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;

		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(a, b);

	if (!sw)
		cout << -1 << endl;

	return 0;
}