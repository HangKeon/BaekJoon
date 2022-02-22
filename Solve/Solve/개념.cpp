#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9						//무한을 의미하는 값으로 10억을 설정

int n, m;							//n : 노드의 개수, m : 간선의 개수
int arr[501][501];					//그래프(플로이드 와샬은 노드가 500개를 넘지 않는 경우 사용!)
									//왜냐하면 3중 반목문을 사용하기 때문!

int main()
{
	cin >> n >> m;

	for (int i = 0; i < 501; i++)			//그래프를 모두 무한으로 초기화
		fill(arr[i], arr[i] + 501, INF);

	for (int i = 1; i <= n; i++)			//자기 자신에서 자기 자신으로 가는 경우 0으로 초기화
		for (int j = 1; j <= n; j++)
			if (i == j)
				arr[i][j] = 0;

	for (int i = 0; i < m; i++)				//각 간선에 대한 정보를 입력 받아 그 값으로 초기화
	{
		int a, b, c;						//a->b로 가는 가중치를 c라 한다

		cin >> a >> b >> c;

		arr[a][b] = c;
	}

	//점화식에 따라 플로이드 와샬 알고리즘 수행
	for (int k = 1; k <= n; k++)					//경유하는 곳				
		for (int a = 1; a <= n; a++)				//출발점
			for (int b = 1; b <= n; b++)			//도착점
				arr[a][b] = min(arr[a][b], arr[a][k] + arr[k][b]);


	for (int a = 1; a <= n; a++)					//수행된 결과 출력
	{
		for (int b = 1; b <= n; b++)
			if (arr[a][b] == INF)					//도달할 수 없는 경우
				cout << "무한" << ' ';
			else									//도달할 수 있는 경우
				cout << arr[a][b] << ' ';

		cout << endl;
	}

	return 0;
}