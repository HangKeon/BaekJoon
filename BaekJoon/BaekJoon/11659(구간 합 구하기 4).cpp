#include <iostream>
using namespace std;
//���׸�Ʈ Ʈ���� ǰ(�����յ� ����!).

int arr[100001];					//�־��� �迭
int tree[4 * 100000];				//���� �� Ʈ��

int init(int s, int e, int node)	//���� �� Ʈ�� ���� -> init(���� �ε���, �� �ε���, ���ؾ� �ϴ� ��� ��ȣ)
{
	if (s == e)						//Ż������ -> ��������� ���
		return tree[node] = arr[s];

	int mid = (s + e) / 2;

	return tree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);	//���� ��� + ������ ���
}

int sum(int s, int e, int node, int l, int r)	//sum(���� �ε���, �� �ε���, ���ϴ� ��� ��ȣ, ���� �� ����)
{
	if (l > e || r < s)							//���� �ۿ� �ִ� ���
		return 0;

	if (l <= s && e <= r)						//���� �ȿ� �ִ� ���
		return tree[node];

	int mid = (s + e) / 2;

	return sum(s, mid, node * 2, l, r) + sum(mid + 1, e, node * 2 + 1, l, r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;						//n : ���� ����, m : ���ؾ� �ϴ� Ƚ��
	int a, b;						//���ؾ� �ϴ� ������ ����

	cin >> n >> m;

	for (int i = 1; i <= n; i++)	//i=1�� �ƴϸ� ������ ������ �����.
		cin >> arr[i];

	init(0, n, 1);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		cout << sum(0, n, 1, a, b) << "\n";
	}

	return 0;
}