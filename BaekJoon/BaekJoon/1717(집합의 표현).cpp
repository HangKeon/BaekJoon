#include <iostream>
using namespace std;

int parent[1000001];

int find(int x)									//찾기
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}

void Union(int a, int b)						//합집합
{
	a = find(a);
	b = find(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main()
{
	ios_base::sync_with_stdio(0);	//코드를 c언어로 취급   -> c++  < c
	cin.tie(0);						//cin 실행속도 향상

	int n, m;						//n : 집합의 마지막 숫자, m : 연산의 개수
	int x, a, b;					//x : 0-> a,b 집합을 합친다, 1 : 같은 집합인지 확인

	cin >> n >> m;

	for (int i = 0; i <= n; i++)	//부모 노드를 자기 자신으로 저장
		parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> a >> b;

		if (x == 0)					//a,b 집합을 합친다
		{
			Union(a, b);
		}
		else if (x == 1)			//a,b가 같은 집합에 있는지 확인
		{
			if (find(a) == find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}