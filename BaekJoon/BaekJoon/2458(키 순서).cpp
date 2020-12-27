#include <iostream>
using namespace std;

int main()
{
	int n, m;						//n : 학생 수, m : 두 학생의 키를 비교한 횟수
	int a, b;
	int cnt = 0;					//자신과 비교할 수 없는 학생의 수
	int ans = 0;					//자신의 키가 몇 번째인지 알 수 있는 학생 수
	int arr[501][501] = { 0, };

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		arr[a][b] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cnt = 0;

		for (int j = 1; j <= n; j++)
		{
			if (i == j)							//자기 자신 제외
				continue;
			if (!arr[i][j] && !arr[j][i])		//i와 j가 연결된 것이 없다면
				cnt++;
		}

		if (cnt == 0)							//모두 다 연결되어 있다면
			ans++;
	}

	cout << ans << endl;


	return 0;
}