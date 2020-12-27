#include <iostream>
using namespace std;

int parent[101];				//부모 노드

int find(int x)
{
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a < b)
		parent[b] = a;				//b의 최상위 부모를 a로 지정
	else							
		parent[a] = b;				//a의 최상위 부모를 b로 지정
}

int main()
{
	int n, m;						//n : 컴퓨터의 수, m : 직접 연결되어 있는 컴퓨터의 쌍 수
	int root;						//컴퓨터 1번에 해당하는 집합
	int ans = 0;					//1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수
	int a, b;

	cin >> n >> m;

	for (int i = 0; i <= n; i++)	//부모 배열을 자기 자신으로 초기화
		parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		Union(a, b);
	}

	root = find(1);

	for (int i = 2; i <= n; i++)
		if (find(i) == root)
			ans++;

	cout << ans << endl;

	return 0;
}