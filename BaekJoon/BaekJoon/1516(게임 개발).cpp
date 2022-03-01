#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;								//�ǹ� ���� ��
int arr[501];						//arr[x] : ���������� ������ �迭(��, x�� �ϱ� ���� ����Ǿ�� �ϴ� �������� ����)
int time[501];						//time[x] : �ǹ� x�� ���µ� �ɸ��� �ð�
int dp[501];						//dp[x] : ����x�� ������ ������ �ɸ��� �ð�
vector<int> v[501];					//�׷���

void topology()
{
	queue<int> q;					//arr ���� 0�� ����(�ǹ� ��ȣ)�� ����

	for (int i = 1; i <= n; i++)	//arr�� 0�� ���i�� q�� ����
		if (!arr[i])
		{
			q.push(i);
			dp[i] = time[i];		//�ڱ� �ڽ��� �ð��� dp�� ����
		}

	for (int i = 1; i <= n; i++)
	{
		int x = q.front();
		q.pop();

		for (int j = 0; j < v[x].size(); j++)
		{
			int y = v[x][j];

			dp[y] = max(dp[y], dp[x] + time[y]);	//max(�� �ǹ� y�� ���µ� �ɸ��� �ð�, �ǹ�x�� ���µ� �ɸ� �ð� + y�� ���µ� �ɸ��� �ð�)

			if (--arr[y] == 0)
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dp[i] << endl;
}

int main()
{
	int a;							//���� �������� �ϴ� �ǹ����� ��ȣ

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> time[i];

		while (1)
		{
			cin >> a;

			if (a == -1)
				break;

			v[a].push_back(i);
			arr[i]++;
		}
	}

	topology();

	return 0;
}