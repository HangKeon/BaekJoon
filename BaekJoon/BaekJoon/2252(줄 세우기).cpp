#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;							//n : 학생 수, m : 키를 비교한 횟수
int arr[32001];						//진입차수 저장할 배열
int result[32001];					//위상 정렬을 통해 큐에서 빠져나온 정점을 저장할 배열
vector<int> v[32001];				//그래프

void topological()
{
	queue<int> q;					//진입차수가 0인 정점을 저장할 큐

	for (int i = 1; i <= n; i++)	//진입차수가 0인 정점을 큐에 저장!
		if (!arr[i])
			q.push(i);

	for (int i = 1; i <= n; i++)
	{
		int x = q.front();			//큐 밖으로 나갈 정점을 x에 저장
		q.pop();
		result[i] = x;
		
		for (int j = 0; j < v[x].size(); j++)
		{
			int y = v[x][j];		//v[x]와 연결된 정점을 y에 저장

			if (--arr[y] == 0)		//arr[y]에서 1 뺀 값이 0이라면 큐에 저장!
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << result[i] << ' ';
	cout << endl;
}

int main()
{
	
	int a, b;					//키를 비교한 두 학생 번호(a->b)

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		v[a].push_back(b);		//그래프 그리기
		arr[b]++;				//b의 진입차수 1 증가
	}

	topological();

	return 0;
}