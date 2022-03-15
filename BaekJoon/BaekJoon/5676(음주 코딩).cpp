#include <iostream>
#include <string>
using namespace std;

int arr[100001];					//�־��� �迭
int tree[4 * 100000 + 1];			//���� �� Ʈ��

int init(int s, int e, int node)	//���� �� Ʈ�� ����� �Լ� -> (���� �ε���, �� �ε���, ���ϴ� ��� ��ȣ)
{
	if (s == e)						//���� ����� ��� -> Ż�� ����
		return tree[node] = arr[s];

	int mid = (s + e) / 2;

	//tree = ���� �ڽ� ��� * ������ �ڽ� ���
	return tree[node] = init(s, mid, node * 2)*init(mid + 1, e, node * 2 + 1);
}

//mul(���� �ε���, �� �ε���, ���ϴ� ��� ��ȣ, ���� �� ����)
int mul(int s, int e, int node, int l, int r)	//���� ���� ���ϴ� �Լ�
{
	if (l > e || r < s)				//���� �ۿ� �ִ� ���
		return 1;

	if (l <= s && e <= r)			//���� �ȿ� �ִ� ���
		return tree[node];

	int mid = (s + e) / 2;

	//���� �ڽ� ��� * ������ �ڽ� ���
	return mul(s, mid, node * 2, l, r)*mul(mid + 1, e, node * 2 + 1, l, r);
}

//update(���� �ε���, �� �ε���, ���ϴ� ��� ��ȣ, �����Ϸ��� ��� ��ȣ, ������ ��)
int update(int s, int e, int node, int idx, int val)
{
	if (idx<s || idx>e)				//�����Ϸ��� �ε����� ���� �ۿ� �ִ� ���
		return tree[node];

	if (s == e)						//���� ����� ��� -> Ż�� ����
		return tree[node] = val;

	int mid = (s + e) / 2;

	//tree = ���� �ڽ� ��� * ������ �ڽ� ���
	return tree[node] = update(s, mid, node * 2, idx, val)*update(mid + 1, e, node * 2 + 1, idx, val);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;						//n : ������ ũ��, k : ���� ���� ��
	char c;							//C : ����, P : ����
	int a, b;						//�Է��ϴ� �� -> C,P�� ���� �ǹ̰� �ٸ� 

	while (cin >> n >> k)
	{
		string str = "";

		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];

			//�����÷ο� �߻��� ���� ���� 1,-1�� ���!
			if (arr[i] > 0)
				arr[i] = 1;
			else if (arr[i] < 0)
				arr[i] = -1;
		}

		init(1, n, 1);					//���� �� Ʈ�� �����

		for (int i = 0; i < k; i++)
		{
			cin >> c >> a >> b;

			if (c == 'C')				//��ȭ
			{
				//�����÷ο� �߻��� ���� ���� 1,-1�� ���!
				if (b > 0)
					b = 1;
				else if (b < 0)
					b = -1;

				update(1, n, 1, a, b);
				arr[a] = b;
			}
			else if (c == 'P')			//����
			{
				int temp = mul(1, n, 1, a, b);

				if (temp == 0)
					//cout << 0;
					str += '0';
				else if (temp > 0)
					//cout << '+';
					str += '+';
				else
					//cout << '-';
					str += '-';
			}
		}
		cout << str<<"\n";
	}

	return 0;
}