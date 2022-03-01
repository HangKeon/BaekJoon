#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;								//�����ؾ� �� �۾��� ��
int ans = 0;						//��� �۾��� �Ϸ��ϱ� ���� �ּ� �ð�
int arr[10001];						//��������(��, ����Ǿ�� �� ����)
int time[10001];					//�۾����� �ɸ��� �ð�
int dp[10001];						//����Ǵ� �۾����� �ɸ��� �ð��� �ִ밪(�ֳ��ϸ� ��� �۾��� �� ������ �ϹǷ�)
vector<int> v[10001];				//v[b] = i : b -> i �� �׷���

void topology()
{
	queue<int> q;					//�����۾��� ���� ���� ����
	
	for (int i = 1; i <= n; i++)
		if (!arr[i])
			q.push(i);

	for (int i = 1; i <= n; i++)
	{
		int x = q.front();
		q.pop();

		for (int j = 0; j < v[x].size(); j++)
		{
			int y = v[x][j];

			dp[y] = max(dp[y], dp[x] + time[y]);	//��� �۾��� �� ������ �ϹǷ� �ִ밪 ����

			if (--arr[y == 0])
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++)					//��� �۾��� ������ ���ؼ� �ִ밪 ã��
		ans = max(ans, dp[i]);

	cout << ans << endl;
}

int main()
{
	int a;							//�� ������ �� �۾��� ���� ���� ���迡 �ִ� �۾����� ����
	int b;							//����Ǿ�� �ϴ� �۾� ��ȣ

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> time[i] >> a;

		dp[i] = time[i];			//�ڱ� �ڽ��� �۾����� �ɸ��� �ð��� ����

		for (int j = 0; j < a; j++)
		{
			cin >> b;

			v[b].push_back(i);		//b -> i�� �׷��� �ۼ�
		}
	}

	topology();

	return 0;
}