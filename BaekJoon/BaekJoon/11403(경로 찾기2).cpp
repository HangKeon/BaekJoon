#include <iostream>
#include <algorithm>
using namespace std;
//플로이드 와샬

int main()
{
	int n;							//정점의 갯수
	int arr[101][101];				//그래프(0 : 간선x, 1 : 간선o)

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << ' ';

		cout << endl;
	}

	return 0;
}