#include <iostream>
using namespace std;

int parent[300001];
int visited[300001];			//방문 여부 확인

int find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);

	parent[a] = b;					//왼쪽 번호가 오른쪽 번호를 부모로 가짐.

	cout << "LADICA\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);						//cin 실행속도 향상

	int n, l;						//n : 술병의 개수, l : 서랍의 개수
	int a, b;						//서랍의 번호
	int temp;						//임시로 저장

	cin >> n >> l;

	for (int i = 0; i <= l; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;

		if (!visited[a])			//1번 규칙
		{
			visited[a] = 1;
			Union(a, b);
		}
		else if (!visited[b])		//2번 규칙
		{
			visited[b] = 1;
			Union(b, a);
		}
		else if (!visited[find(a)])	//3번 규칙
		{
			temp = find(a);
			visited[temp] = 1;
			Union(a, b);
		}
		else if (!visited[find(b)])	//4번 규칙
		{
			temp = find(b);
			visited[temp] = 1;
			Union(b, a);
		}
		else						//5번 규칙
		{
			cout << "SMECE\n";
		}
	}

	return 0;
}