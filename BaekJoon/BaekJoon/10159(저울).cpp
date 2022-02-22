#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;							//물건의 개수
	int m;							//물건 쌍의 개수
	int a, b;						//측정된 물건의 번호
	int cnt = 0;					//비교 결과를 알 수 없는 물건의 개수
	int arr[101][101] = { 0, };		//arr[a][b] : a > b인 경우 1로 존재

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		arr[a][b] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (arr[i][k] && arr[k][j])		//이런 식으로 경유해서 크기를 알 수 있는 경우
					arr[i][j] = 1;

	for (int i = 1; i <= n; i++)
	{
		cnt = 0;

		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;

			if (!arr[i][j] && !arr[j][i])		//경유해서도 알 수 없는 경우
				cnt++;
		}

		cout << cnt << endl;
	}

	return 0;
}
