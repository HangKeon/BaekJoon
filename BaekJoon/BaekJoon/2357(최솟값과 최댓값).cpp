#include <iostream>
#include <algorithm>
using namespace std;
//���׸�Ʈ Ʈ��

int arr[100001];						//�־��� �迭
int min_tree[4 * 100000 + 1];			//�ּ� ���� Ʈ��
int max_tree[4 * 100000 + 1];			//�ִ� ���� Ʈ��

int min_init(int s, int e, int node)	//�ּ� ���� Ʈ�� ����� �Լ� -> min_init(���� �ε���, �� �ε���, ���ϴ� ���)
{
	if (s == e)							//���� ����� -> Ż�� ����
		return min_tree[node] = arr[s];

	int mid = (s + e) / 2;

	return min_tree[node] = min(min_init(s, mid, node * 2), min_init(mid + 1, e, node * 2 + 1));
}

int max_init(int s, int e, int node)	//�ִ� ���� Ʈ�� ����� �Լ� -> max_init(���� �ε���, �� �ε���, ���ϴ� ���)
{
	if (s == e)							//���� ����� -> Ż�� ����
		return max_tree[node] = arr[s];

	int mid = (s + e) / 2;

	return max_tree[node] = max(max_init(s, mid, node * 2), max_init(mid + 1, e, node * 2 + 1));
}

int min_find(int s, int e, int node, int l, int r)	//�ּ� ã�� �Լ� -> min_find(���� �ε���, �� �ε���, ���ϴ� ���, ����)
{
	if (l > e || r < s)					//���� �ۿ� �ִ� ���
		return 1e9;

	if (l <= s && e <= r)				//���� �ȿ� �ִ� ���
		return min_tree[node];

	int mid = (s + e) / 2;

	return min(min_find(s, mid, node * 2, l, r), min_find(mid + 1, e, node * 2 + 1, l, r));
}

int max_find(int s, int e, int node, int l, int r)	//�ִ� ã�� �Լ� -> min_find(���� �ε���, �� �ε���, ���ϴ� ���, ����)
{
	if (l > e || r < s)					//���� �ۿ� �ִ� ���
		return -1e9;

	if (l <= s && e <= r)				//���� �ȿ� �ִ� ���
		return max_tree[node];

	int mid = (s + e) / 2;

	return max(max_find(s, mid, node * 2, l, r), max_find(mid + 1, e, node * 2 + 1, l, r));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;							//n : ������ ����, m : ������ ����
	int a, b;							//����

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	min_init(1, n, 1);						//�ּ� ���� Ʈ�� �ϼ�
	max_init(1, n, 1);						//�ִ� ���� Ʈ�� �ϼ�

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		cout << min_find(1, n, 1, a, b) << ' ' << max_find(1, n, 1, a, b) << "\n";
	}

	return 0;
}