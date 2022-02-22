#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;							//n : ������ ��, m : ������ ����
	int arr[101][101];					//arr[���� ����][���� ����] = ���

	cin >> n >> m;

	//for (int i = 0; i < 101; i++)		//�ʱ�ȭ
		fill(arr[0], arr[101] , 1e7);

	for (int i = 1; i <= n; i++)		//�ڱ� �ڽ��� 0���� �ʱ�ȭ
		for (int j = 1; j <= n; j++)
			if (i == j)
				arr[i][j] = 0;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;					//���۵���, ���� ����, ���

		cin >> a >> b >> c;

		if (arr[a][b] > c)				//������ �ϳ��� �ƴ� �� �ֱ� ����
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