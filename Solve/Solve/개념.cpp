#include <iostream>
using namespace std;

int parent[9];								//부모 노드(0,1~8)

int find(int x)								//특정한 노드의 부모를 찾는 함수
{
	if(parent[x] == x)						//만약 부모의 값이 x라는 값과 동일하다면
		return x;							//x를 반환

	return parent[x] = find(parent[x]);		//부모 노드의 값과 자기 자신의 값이 다른 경우
											//find 하면서 만난 모든 값의 부모 노드를 parent로 만듦
}

void Union(int a, int b)					//두 부모 노드를 합치는 함수(a < b)
{
	a = find(a);
	b = find(b);

	parent[b] = a;							//작은 쪽으로 부모의 번호를 바꾼다
}


int main()
{
	for (int i = 1; i <= 8; i++)
		parent[i] = i;						//기본적으로 자기 자신을 부모로 가리키도록 만듦

	Union(1, 2);	//parent[2]=1
	Union(2, 3);	//parent[3]=1
	Union(3, 4);	//parent[4]=1

	Union(5, 6);	//parent[6]=5
	Union(6, 7);	//parent[7]=5
	Union(7, 8);	//parent[8]=5


	return 0;
}