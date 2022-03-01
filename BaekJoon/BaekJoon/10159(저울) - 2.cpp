#include <iostream>
using namespace std;

int arr[101][101];					//arr[i][j] : i>j인 경우 1을 저장
int cnt[101];						//cnt[i] : 물건 i와 비교 결과를 알 수 없는 물건의 개수

int main()
{
	int n, m;						//n : 물건의 개수, m : 미리 측정된 물건 쌍 개수
	int a, b;						//측정된 물건 번호

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		arr[a][b] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j && !arr[i][j] && !arr[j][i])	//자기 자신을 제외 + 비교할 수 없는 경우
				cnt[i]++;

	for (int i = 1; i <= n; i++)
		cout << cnt[i] << endl;

	return 0;
}