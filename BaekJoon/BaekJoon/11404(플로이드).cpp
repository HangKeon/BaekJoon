#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;							//n : 도시의 수, m : 버스의 개수
	int arr[101][101];					//arr[시작 도시][도착 도시] = 비용

	cin >> n >> m;

	//for (int i = 0; i < 101; i++)		//초기화
		fill(arr[0], arr[101] , 1e7);

	for (int i = 1; i <= n; i++)		//자기 자신은 0으로 초기화
		for (int j = 1; j <= n; j++)
			if (i == j)
				arr[i][j] = 0;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;					//시작도시, 도착 도시, 비용

		cin >> a >> b >> c;

		if (arr[a][b] > c)				//간선이 하나가 아닐 수 있기 때문
			arr[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (arr[i][j] == 1e7)
				cout << 0 << ' ';
			else
				cout << arr[i][j] << ' ';

		cout << endl;
	}

	return 0;
}