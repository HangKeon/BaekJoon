#include <iostream>
#include <algorithm>
using namespace std;

int arr[401][401];				//사건 전후 관계를 저장

int main()
{
	ios::sync_with_stdio(0);	//이거 안 하면 시간초과 난다.
	cin.tie(0);
	cout.tie(0);

	int n;						//사건의 개수
	int k;						//사건 전후 관계 개수
	int a, b;					//사건 번호(a가 b보다 먼저 일어남)
	int s;						//사건 전후 관계를 알고 싶은 사건의 쌍 수

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;

		arr[a][b] = -1;
		arr[b][a] = 1;
	}

	for (int t = 1; t <= n; t++)			//플로이드 와샬
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (!arr[i][j])									//i,j 두 사건이 관계가 없을 때
					if (arr[i][t] == 1 && arr[t][j] == 1)			//t->i, j->t 로 관계를 알 수 있다면
						arr[i][j] = 1;								//j->i라는 관계가 생긴다.
					else if (arr[i][t] == -1 && arr[t][j] == -1)	//i->t, t->j 로 관계를 알 수 있다면
						arr[i][j] = -1;								//i->j라는 관계가 생긴다.

	cin >> s;

	for (int i = 0; i < s; i++)
	{
		cin >> a >> b;

		cout << arr[a][b] << "\n";
	}

	return 0;
}