#include <iostream>
using namespace std;

int arr[] = { 1,9,3,8,4,5,5,9,10,3,4,5 };			//�迭�� �� 12��
int tree[4 * 12];									//arr�� ũ�� x 4 �� Ʈ���� �����.

//Ʈ���� ����� �ִ� �Լ�
int init(int s, int e, int node)					//init(���� �ε���, �� �ε���, ���ϴ� ��� ��ȣ)
{
	if (s == e)										//Ż�� ���� -> ������ 1�� ���� ���
		return tree[node] = arr[s];

	int mid = (s + e) / 2;

	//���� ��� + ������ ��带 ��� �Լ��� ���� �����ش�.
	return tree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

int sum(int s, int e, int node, int l, int r)		//sum(���� �ε���, �� �ε���, ���ϴ� ��� ��ȣ, ���� �� ����)
{
	if (l > e || r < s)								//���� �ۿ� �ִ� ���
		return 0;

	if (l <= s && e <= r)							//���� �ȿ� �ִ� ���
		return tree[node];

	//�׷��� ���� ��� �� �κ����� ������ ���� ���Ѵ�.
	int mid = (s + e) / 2;

	return sum(s, mid, node * 2, l, r) + sum(mid + 1, e, node * 2 + 1, l, r);
}

//update(���� �ε���, �� �ε���, ���ϴ� ��� ��ȣ, �����Ϸ��� ��� ��ȣ, ������ ���� ����)
void update(int s, int e, int node, int idx, int val)	
{
	if (idx<s || idx>e)								//���� �ۿ� �ִ� ���
		return;

	//���� �ȿ� �ִٸ� �������� �ٸ� ���ҵ� �����Ѵ�.

	tree[node] += val;								//���� �� Ʈ���� val�� ���Ѵ�.

	if (s == e)										//Ż�� ���� -> ������ 1�� ���� ���
		return;

	//�׷��� ���� ��� �� �κ����� ������ ���� ���Ѵ�.
	int mid = (s + e) / 2;

	update(s, mid, node * 2, idx, val);				//���� �ڽ� ���
	update(mid + 1, e, node * 2 + 1, idx, val);		//������ �ڽ� ���
}

int main()
{
	init(0, 11, 1);									//���� �� Ʈ�� ����

	//���� �� ���ϱ�
	cout << "�ε��� 0 ~ 11�� ������ : " << sum(0, 11, 1, 0, 11) << endl;

	//���� �� ���ϱ�
	cout << "�ε��� 4 ~ 8�� ������ : " << sum(0, 11, 1, 4, 8) << endl;

	//���� �� ����
	cout << "<�ε��� 7�� ���Ҹ� 1��ŭ ����>" << endl;
	update(0, 11, 1, 7, 1);

	// ���� �� ���ϱ�
	cout << "�ε��� 6 ~ 11�� ������ : " << sum(0, 11, 1, 6, 11) << endl;

	return 0;
}