#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;							//n : 가수의 수, m : 보조 PD의 수
int arr[1001];						//진입차수(즉, 자신 이전에 선행되어야 하는 가수의 수)
int brr[101];						//보조 PD가 담당하는 가수들 번호
vector<int> v[1001];				//v[x]=y : x -> y인 그래프

void topology()
{
	queue<int> q;					//진입차수가 0인 정점을 저장
	int result[1001];				//가수 출연 순서 저장(위상 정렬 순서)

	for (int i = 1; i <= n; i++)	//진입차수가 0이면 q에 대입
		if (!arr[i])
			q.push(i);

	for (int i = 1; i <= n; i++)
	{
		if (q.empty())				//순서를 정하는 것이 불가능한 경우(즉, 사이클 발생)
		{
			cout << 0 << endl;
			return;
		}


		int x = q.front();			//q에서 나가는 값을 저장
		q.pop();
		result[i] = x;

		for (int j = 0; j < v[x].size(); j++)
		{
			int y = v[x][j];		//정점 x와 연결된 정점

			if (--arr[y] == 0)		//arr[y]에서 1을 뺀 값이 0이라면 q에 대입
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << result[i] << endl;
}

int main()
{
	int a, b;						//a : 담당한 가수의 수, b : 가수의 순서

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a;

		for (int j = 0; j < a; j++)				//가수 번호 입력
			cin >> brr[j];
		
		for (int j = 0; j < a - 1; j++)			//가수 끼리 위상 정렬 그래프 만듦
		{
			v[brr[j]].push_back(brr[j + 1]);	//그래프 생성
			arr[brr[j + 1]]++;					//진입차수 1 증가
		}
	}

	topology();

	return 0;
}