#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int> > v[100001];		//연결된 (동굴들의 번호, 간선 크기)를 저장하는 배열
int check[100001];						//방문한 방은 1을, 방문하지 않았다면 0을 저장
int ans;								//(간선의 총 합 - 간선 중 가장 긴 값)을 저장할 배열
int n, x, y;							//n = 동굴의 방의 개수, x,y = 두 로봇이 위치한 방의 번호

void dfs(int now, int cost, int mcost)	//dfs(현재 노드, 총 간선 길이의 합, 가장 긴 간선 길이)
{
	check[now] = 1;						//현재 노드(now)는 지금 막 방문했으므로 1을 대입

	if (now == y)						//탈출조건 -> 끝 값(end)에 도착한 경우
	{
		ans = cost - mcost;
		return;
	}

	for (auto i : v[now])
	{
		if (!check[i.first])				//만약 현재 노드(now)와 연결된 다음 노드(i.first)를 아직 방문하지 않았다면
		{
			dfs(i.first, cost + i.second, max(mcost, i.second));
		}
	}
}

int main()
{
	int start, end, len;				//start,end = 양 끝에 위치한 방의 번호, len = 통로의 길이

	cin >> n >> x >> y;

	for (int i = 1; i < n; i++)
	{
		cin >> start >> end >> len;

		v[start].push_back({ end,len });	//두 방 start,end가 간선의 길이 len만큼 연결되어 있음을 알려주는 배열
		v[end].push_back({ start,len });
	}

	dfs(x, 0, 0);							//dfs(시작 노드, 간선 총합 = 0, 가장 긴 간선 길이 -> 처음에 가장 작은 값으로 지정)

	cout << ans << endl;

	return 0;
}