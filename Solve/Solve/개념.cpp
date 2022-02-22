#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9						//������ �ǹ��ϴ� ������ 10���� ����

int n, m;							//n : ����� ����, m : ������ ����
int arr[501][501];					//�׷���(�÷��̵� �ͼ��� ��尡 500���� ���� �ʴ� ��� ���!)
									//�ֳ��ϸ� 3�� �ݸ��� ����ϱ� ����!

int main()
{
	cin >> n >> m;

	for (int i = 0; i < 501; i++)			//�׷����� ��� �������� �ʱ�ȭ
		fill(arr[i], arr[i] + 501, INF);

	for (int i = 1; i <= n; i++)			//�ڱ� �ڽſ��� �ڱ� �ڽ����� ���� ��� 0���� �ʱ�ȭ
		for (int j = 1; j <= n; j++)
			if (i == j)
				arr[i][j] = 0;

	for (int i = 0; i < m; i++)				//�� ������ ���� ������ �Է� �޾� �� ������ �ʱ�ȭ
	{
		int a, b, c;						//a->b�� ���� ����ġ�� c�� �Ѵ�

		cin >> a >> b >> c;

		arr[a][b] = c;
	}

	//��ȭ�Ŀ� ���� �÷��̵� �ͼ� �˰��� ����
	for (int k = 1; k <= n; k++)					//�����ϴ� ��				
		for (int a = 1; a <= n; a++)				//�����
			for (int b = 1; b <= n; b++)			//������
				arr[a][b] = min(arr[a][b], arr[a][k] + arr[k][b]);


	for (int a = 1; a <= n; a++)					//����� ��� ���
	{
		for (int b = 1; b <= n; b++)
			if (arr[a][b] == INF)					//������ �� ���� ���
				cout << "����" << ' ';
			else									//������ �� �ִ� ���
				cout << arr[a][b] << ' ';

		cout << endl;
	}

	return 0;
}