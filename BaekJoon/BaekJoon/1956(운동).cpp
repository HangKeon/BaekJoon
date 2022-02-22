#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9

long long arr[401][401];				//�׷���

int main()
{
	int v, e;							//v : ������ ��, e : ������ ��
	long long temp = INF;				//����Ŭ ���� ���� Ȯ��(INF�̸� ����Ŭ�� ���ٴ� ��)

	cin >> v >> e;

	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			if (i != j)
				arr[i][j] = INF;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;				//���� ����, ���� ����, �Ÿ�

		cin >> a >> b >> c;

		arr[a][b] = c;
	}

	for (int k = 1; k <= v; k++)
		for (int a = 1; a <= v; a++)
			for (int b = 1; b <= v; b++)
			{
				arr[a][b] = min(arr[a][b], arr[a][k] + arr[k][b]);

				if (a != b)
					temp = min(temp, arr[a][b] + arr[b][a]);
			}

	/*for (int a = 1; a <= v; a++)
	{
		for (int b = 1; b <= v; b++)
		{
			if (a == b)
				continue;

			if (arr[a][b] != INF && arr[b][a] != INF)
				temp = min(temp, arr[a][b] + arr[b][a]);
		}

	}*/

	if (temp == INF)
		cout << -1 << endl;
	else
		cout << temp << endl;


	return 0;
}