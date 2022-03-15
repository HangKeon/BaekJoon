#include <iostream>
#include <algorithm>
using namespace std;
//���׸�Ʈ Ʈ��

#define MAX 1000000
#define ll long long

long long arr[MAX + 1];				//�־��� �迭
long long tree[MAX * 4 + 1];		//���� �� Ʈ��

ll init(ll s, ll e, ll node)	//���� �� Ʈ�� ����� �Լ� -> init(���� �ε���, �� �ε���, ���ϴ� ���)
{
	if (s == e)						//���� ����� ��� -> Ż�� ����
		return tree[node] = arr[s];

	ll mid = (s + e) / 2;

	return tree[node] = (init(s, mid, node * 2) * init(mid + 1, e, node * 2 + 1)) % 1000000007;	//���� �ڽ� ��� + ������ �ڽ� ���
}

ll mul(ll s, ll e, ll node, ll l, ll r)	//���� �� ���ϴ� �Լ� ->mul(���� �ε���, �� �ε���, ���ϴ� ���, ���� �� ����)
{
	if (l > e || r < s)				//���� �ۿ� �ִ� ���
		return 1;

	if (l <= s && e <= r)			//���� �ȿ� �ִ� ���
		return tree[node];

	ll mid = (s + e) / 2;

	return (mul(s, mid, node * 2, l, r) * mul(mid + 1, e, node * 2 + 1, l, r)) % 1000000007;	//���� �ڽ� ��� * ������ �ڽ� ���
}

//update(���� �ε���, �� �ε���, ���ϴ� ��� ��ȣ, �����Ϸ��� ��� ��ȣ, ������ ���� ����)
ll update(ll s, ll e, ll node, ll idx, ll val)
{
	if (idx < s || idx > e)			//�����Ϸ��� �ε����� ���� �ۿ� �ִ� ���
		return tree[node];

	//tree[node] += val;				//�̰� ���� ���� ���!


	if (s == e)						//Ż�� ���� -> ������ 1�� ���� ���
		return tree[node] = val;

	ll mid = (s + e) / 2;

	//update(s, mid, node * 2, idx, val);				//���� �ڽ� ���
	//update(mid + 1, e, node * 2 + 1, idx, val);		//������ �ڽ� ���

	return tree[node] = (update(s, mid, node * 2, idx, val)*update(mid + 1, e, node * 2 + 1, idx, val)) % 1000000007;
}

int main()
{
	long long n, m, k;				//n : ���� ����, m : ������ �Ͼ�� Ƚ��, k : ������ �� ���ϴ� Ƚ��
	long long a, b, c;				//a : 1 -> b��° ���� c�� �ٲ�
									//    2 -> b ~ c��° �������� ���� ���

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(1, n, 1);					//���� �� Ʈ�� �ϼ�

	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;

		if (a == 1)								//a == 1�̸�
		{
			update(1, n, 1, b, c);				//b��° ���� c�� �ٲ�
			arr[b] = c;							//arr ���� c�� �ٲ���� �Ѵ� -> �� �Ѵٸ� c�� ������ ���� ���� ���� �� ���� �ٲ��� �ʾ� ������ �߻�!
		}
		else if (a == 2)						//a == 2�̸�
			cout << mul(1, n, 1, b, c) << "\n";	//b ~ c��° �������� ���� ���
	}

	return 0;
}