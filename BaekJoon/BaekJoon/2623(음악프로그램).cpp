#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;							//n : ������ ��, m : ���� PD�� ��
int arr[1001];						//��������(��, �ڽ� ������ ����Ǿ�� �ϴ� ������ ��)
int brr[101];						//���� PD�� ����ϴ� ������ ��ȣ
vector<int> v[1001];				//v[x]=y : x -> y�� �׷���

void topology()
{
	queue<int> q;					//���������� 0�� ������ ����
	int result[1001];				//���� �⿬ ���� ����(���� ���� ����)

	for (int i = 1; i <= n; i++)	//���������� 0�̸� q�� ����
		if (!arr[i])
			q.push(i);

	for (int i = 1; i <= n; i++)
	{
		if (q.empty())				//������ ���ϴ� ���� �Ұ����� ���(��, ����Ŭ �߻�)
		{
			cout << 0 << endl;
			return;
		}


		int x = q.front();			//q���� ������ ���� ����
		q.pop();
		result[i] = x;

		for (int j = 0; j < v[x].size(); j++)
		{
			int y = v[x][j];		//���� x�� ����� ����

			if (--arr[y] == 0)		//arr[y]���� 1�� �� ���� 0�̶�� q�� ����
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << result[i] << endl;
}

int main()
{
	int a, b;						//a : ����� ������ ��, b : ������ ����

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a;

		for (int j = 0; j < a; j++)				//���� ��ȣ �Է�
			cin >> brr[j];
		
		for (int j = 0; j < a - 1; j++)			//���� ���� ���� ���� �׷��� ����
		{
			v[brr[j]].push_back(brr[j + 1]);	//�׷��� ����
			arr[brr[j + 1]]++;					//�������� 1 ����
		}
	}

	topology();

	return 0;
}