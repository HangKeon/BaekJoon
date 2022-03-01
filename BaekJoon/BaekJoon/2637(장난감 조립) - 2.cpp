#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;								//��ǰ ��ȣ(1~n-1 : �⺻ ��ǰ/�߰� ��ǰ, n : ����ǰ ��ȣ)
int arr[101];						//���� ����(��, ����Ǿ�� �ϴ� �������� ����) -> �ݴ�� ����!
int arr2[101];						//���� ���� ����(��, ����Ǿ�� �ϴ� �������� ����)
int dp[101];						//�ʿ��� �⺻ ��ǰ�� ������ ����
vector<pair<int,int> > v[101];		//v[x] = {y, k} : �׷���(y -> x�� ��, x�� ����� ���� y�� k�� �ʿ�)
									//but ȭ��ǥ�� �ݴ�� �����ؼ� Ǯ��!(��, x -> y�� ��, y�� ����� ���� x�� k�� �ʿ�)

void topology()
{
	queue<int> q;					//���������� 0�� ���� ����

	for(int i=1;i<=n;i++)
		if (!arr[i])
			q.push(i);

	dp[n] = 1;

	for (int i = 1; i <= n; i++)
	{
		int x = q.front();
		q.pop();

		for (int j = 0; j < v[x].size(); j++)
		{
			int a = v[x][j].first;	//x�� ����� ��ǰ ��ȣ
			int b = v[x][j].second;	//b�� a�� ����� �� �ʿ��� x�� ���� ����

			dp[a] += b * dp[x];

			if (--arr[a] == 0)
				q.push(a);
		}
	}

	for (int i = 1; i <= n; i++)	//arr2�� 0�� ��츸 ���(�⺻ ��ǰ�� ���)
		if (!arr2[i])
			cout << i << ' ' << dp[i] << endl;
}

int main()
{
	int m;							//��ǰ�� ���� ������ ����
	int x, y, k;					//x : �߰� ��ǰ/����ǰ, y : �⺻ ��ǰ/�߰� ��ǰ, k : x�� ����� ���� y�� ����

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> k;

		v[x].push_back({ y,k });	//(x -> y), [ū�� -> ���� ��]���� �ؼ� �ݴ�� ����
		arr[y]++;					//y�� �������� 1 ����
		arr2[x]++;					//���� ���� ������ 1 ����
	}

	topology();

	return 0;
}