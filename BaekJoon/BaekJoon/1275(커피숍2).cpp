#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100001];				//�־��� �迭
long long tree[4 * 100000 + 1];		//���� Ʈ��

long long init(int s, int e, int node)	//���� Ʈ�� ����� �Լ� -> init(���� �ε���, �� �ε���, ���ϴ� ���)
{
	if (s == e)						//���� ����� ��� -> Ż�� ����
		return tree[node] = arr[s];

	int mid = (s + e) / 2;

	return tree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);	//���� �ڽ� ��� + ������ �ڽ� ���
}

long long sum(int s, int e, int node, int l, int r)	//���� �� ���ϴ� �Լ� -> sum(���� �ε���, �� �ε���, ���ϴ� ��� ��ȣ, ���� �� ����)
{
	if (l > e || r < s)				//���� �ۿ� �ִ� ���
		return 0;

	if (l <= s && e <= r)			//���� �ȿ� �ִ� ���
		return tree[node];

	int mid = (s + e) / 2;

	return sum(s, mid, node * 2, l, r) + sum(mid + 1, e, node * 2 + 1, l, r);
}

//update(���� �ε���, �� �ε���, ���ϴ� ��� ��ȣ, �����Ϸ��� ��� ��ȣ, ������ ���� ����)
void update(int s, int e, int node, int idx, long long val)
{
	if (idx<s || idx>e)				//�����Ϸ��� �ε����� ���� �ۿ� �ִ� ���
		return;

	tree[node] += val;

	if (s == e)						//���� ����� ��� -> Ż�� ����
		return;

	int mid = (s + e) / 2;

	update(s, mid, node * 2, idx, val);				//���� �ڽ� ���
	update(mid + 1, e, node * 2 + 1, idx, val);		//������ �ڽ� ���
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;					//n : ���� ����, m : ���� ����
	int x, y, a, b;				//x~y������ ���� ���ض� + a��° ���� b�� �ٲ��

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(1, n, 1);

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> a >> b;

		int _x = min(x, y);
		int _y = max(x, y);

		cout << sum(1, n, 1, _x, _y) << "\n";

		update(1, n, 1, a, b - arr[a]);

		arr[a] = b;								//arr[a]�� b�� �ٲ���� ���� �� ��꿡 ������ ���� �ʴ´�.
	}

	return 0;
}