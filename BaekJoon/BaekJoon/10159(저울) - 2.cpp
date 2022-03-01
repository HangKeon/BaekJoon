#include <iostream>
using namespace std;

int arr[101][101];					//arr[i][j] : i>j�� ��� 1�� ����
int cnt[101];						//cnt[i] : ���� i�� �� ����� �� �� ���� ������ ����

int main()
{
	int n, m;						//n : ������ ����, m : �̸� ������ ���� �� ����
	int a, b;						//������ ���� ��ȣ

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
			if (i != j && !arr[i][j] && !arr[j][i])	//�ڱ� �ڽ��� ���� + ���� �� ���� ���
				cnt[i]++;

	for (int i = 1; i <= n; i++)
		cout << cnt[i] << endl;

	return 0;
}