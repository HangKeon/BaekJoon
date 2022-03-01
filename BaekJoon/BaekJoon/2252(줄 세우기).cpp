#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;							//n : �л� ��, m : Ű�� ���� Ƚ��
int arr[32001];						//�������� ������ �迭
int result[32001];					//���� ������ ���� ť���� �������� ������ ������ �迭
vector<int> v[32001];				//�׷���

void topological()
{
	queue<int> q;					//���������� 0�� ������ ������ ť

	for (int i = 1; i <= n; i++)	//���������� 0�� ������ ť�� ����!
		if (!arr[i])
			q.push(i);

	for (int i = 1; i <= n; i++)
	{
		int x = q.front();			//ť ������ ���� ������ x�� ����
		q.pop();
		result[i] = x;
		
		for (int j = 0; j < v[x].size(); j++)
		{
			int y = v[x][j];		//v[x]�� ����� ������ y�� ����

			if (--arr[y] == 0)		//arr[y]���� 1 �� ���� 0�̶�� ť�� ����!
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << result[i] << ' ';
	cout << endl;
}

int main()
{
	
	int a, b;					//Ű�� ���� �� �л� ��ȣ(a->b)

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		v[a].push_back(b);		//�׷��� �׸���
		arr[b]++;				//b�� �������� 1 ����
	}

	topological();

	return 0;
}