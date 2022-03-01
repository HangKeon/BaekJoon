#include <iostream>
#include <algorithm>
using namespace std;

int arr[401][401];				//��� ���� ���踦 ����

int main()
{
	ios::sync_with_stdio(0);	//�̰� �� �ϸ� �ð��ʰ� ����.
	cin.tie(0);
	cout.tie(0);

	int n;						//����� ����
	int k;						//��� ���� ���� ����
	int a, b;					//��� ��ȣ(a�� b���� ���� �Ͼ)
	int s;						//��� ���� ���踦 �˰� ���� ����� �� ��

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;

		arr[a][b] = -1;
		arr[b][a] = 1;
	}

	for (int t = 1; t <= n; t++)			//�÷��̵� �ͼ�
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (!arr[i][j])									//i,j �� ����� ���谡 ���� ��
					if (arr[i][t] == 1 && arr[t][j] == 1)			//t->i, j->t �� ���踦 �� �� �ִٸ�
						arr[i][j] = 1;								//j->i��� ���谡 �����.
					else if (arr[i][t] == -1 && arr[t][j] == -1)	//i->t, t->j �� ���踦 �� �� �ִٸ�
						arr[i][j] = -1;								//i->j��� ���谡 �����.

	cin >> s;

	for (int i = 0; i < s; i++)
	{
		cin >> a >> b;

		cout << arr[a][b] << "\n";
	}

	return 0;
}