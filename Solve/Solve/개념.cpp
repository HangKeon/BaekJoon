#include <iostream>
using namespace std;

int parent[9];								//�θ� ���(0,1~8)

int find(int x)								//Ư���� ����� �θ� ã�� �Լ�
{
	if(parent[x] == x)						//���� �θ��� ���� x��� ���� �����ϴٸ�
		return x;							//x�� ��ȯ

	return parent[x] = find(parent[x]);		//�θ� ����� ���� �ڱ� �ڽ��� ���� �ٸ� ���
											//find �ϸ鼭 ���� ��� ���� �θ� ��带 parent�� ����
}

void Union(int a, int b)					//�� �θ� ��带 ��ġ�� �Լ�(a < b)
{
	a = find(a);
	b = find(b);

	parent[b] = a;							//���� ������ �θ��� ��ȣ�� �ٲ۴�
}


int main()
{
	for (int i = 1; i <= 8; i++)
		parent[i] = i;						//�⺻������ �ڱ� �ڽ��� �θ�� ����Ű���� ����

	Union(1, 2);	//parent[2]=1
	Union(2, 3);	//parent[3]=1
	Union(3, 4);	//parent[4]=1

	Union(5, 6);	//parent[6]=5
	Union(6, 7);	//parent[7]=5
	Union(7, 8);	//parent[8]=5


	return 0;
}