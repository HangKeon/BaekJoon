#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[1001];		//도시가 연결되어 있음을 표현하기 위한 벡터
//int visited[1001] = { 0, };			//도시의 방문을 확인하는 배열
//int arr[101];					//출력값 저장
int k;						//배열 a의 인덱스
int cnt;					//모든 도시 여행 위한 최소 비행기 종류

void bfs(int s)				//bfs(출발하는 도시)
{
	queue<int> q;
	int visited[1001] = { 0, };			//도시의 방문을 확인하는 배열
	cnt = 0;				//테스트 케이스 수만큼 확인해야 하므로 초기화 필요!

	q.push(s);
	visited[s] = 1;			//방문처리

	while (!q.empty())
	{
		int x = q.front();

		q.pop();

		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];

			if (!visited[y])
			{
				q.push(y);
				visited[y] = 1;
				cnt++;
			}
		}
	}

	cout << cnt << endl;
	//arr[k++] = cnt;
}

/*void dfs(int x)
{
	visited[x] = 1;



}*/

int main()
{
	int t;					//테스트 케이스 수
	int n, m;				//n : 국가의 수, m : 비행기 종류
	int a, b;				//a와 b를 왕복하는 비행기 존재

	cin >> t;


	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;

		for (int j = 0; j < m; j++)
		{
			cin >> a >> b;

			v[a].push_back(b);
			v[b].push_back(a);
		}

		bfs(1);

		for (int j = 0; j < n; j++)			//여러 테스트 타입을 입력할 경우 다시 값들을 전부 비워야 한다
			v[j].clear();					//아니면 전에 값에 영향을 미친다
	}

	//for (int i = 0; i < k; i++)
	//	cout << arr[i] << endl;

	return 0;
}

//for (int j = 0; j < n; j++)
//	v[j].clear();
//위의 코드가 없다면 아래 예시에서 문제가 생긴다.
/*2
5 6
1 2
1 3
1 4
1 5
2 3
3 4
3 3
1 2
2 3
1 3
*/