#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n = 7;								//정점 개수
int arr[8];								//진입 차수 개수
vector<int> v[8];						//위상 정렬 그래프

void topological();						//함수 프로토타입

int main()
{
	v[1].push_back(2);					//1 -> 2
	arr[2]++;							//정점 2의 진입 차수를 1 증가

	v[1].push_back(5);					//1 -> 5
	arr[5]++;							//정점 5의 진입 차수를 1 증가

	v[2].push_back(3);					//2 -> 3
	arr[3]++;							//정점 3의 진입 차수를 1 증가

	v[3].push_back(4);					//3 -> 4
	arr[4]++;							//정점 4의 진입 차수를 1 증가

	v[4].push_back(6);					//4 -> 6
	arr[6]++;							//정점 6의 진입 차수를 1 증가

	v[5].push_back(6);					//5 -> 6
	arr[6]++;							//정점 6의 진입 차수를 1 증가

	v[6].push_back(7);					//6 -> 7
	arr[7]++;							//정점 7의 진입 차수를 1 증가

	topological();

	return 0;
}

void topological()
{
	int result[8];						//큐에서 꺼낸 정점을 순서대로 저장(위상 정렬 순서)
	queue<int> q;						//진입 차수가 0인 정점을 넣을 큐

	for (int i = 1; i <= n; i++)		//진입 차수가 0인 정점을 큐에 삽입
		if (arr[i] == 0)
			q.push(i);

	for (int i = 1; i <= n; i++)		//정렬이 완전히 수행되려면 정확히 n개의 정점을 방문
	{
		if (q.empty())					//n개를 방문하기 전에 큐가 비어버리면 사이클 발생한 것
		{
			cout << "사이클이 발생했습니다." << endl;
			return;
		}

		int x = q.front();				//큐에서 꺼낼 정점을 미리 저장

		q.pop();						//큐에서 정점을 꺼냄

		result[i] = x;					//꺼낸 정점을 순서대로 저장

		for (int j = 0; j < v[x].size(); j++)	//정점x와 연결된 정점을 모두 살펴본다
		{
			int y = v[x][j];					//정점x가 가진 정점을 y에 저장
			
			if (--arr[y] == 0)					//정점y의 진입차수 개수를 하나 뺐을 때 개수가 0이면 q에 삽입
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++)				//위상 정렬 결과 출력
		cout << result[i] << ' ';

	cout << endl;
}