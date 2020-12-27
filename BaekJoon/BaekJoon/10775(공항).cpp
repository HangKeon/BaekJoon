#include <iostream>
using namespace std;

int parent[100001];					//이것이 가리키는 게이트에 연결

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

	parent[a] = b;				//a > b
}

int main()
{
	int g, p;						//g :  게이트 개수, p : 비행기 개수
	int a;
	int cnt = 0;					//도킹시킬 수 있는 비행기 수

	cin >> g >> p;

	for (int i = 1; i <= g; i++)	//parent 배열 초기화
		parent[i] = i;

	for (int i = 1; i <= p; i++)
	{
		cin >> a;

		int par = find(a);

		if (par == 0)			// 0까지 갔다는 것은 도킹 가능한 게이트가 없다는 것을 의미
			break;
		
		// 도킹하려는 게이트의 부모 노드가 0이 아니라면 해당 게이트는 도킹되었지만
		//아직 그보다 숫자가 작은 게이트에 도킹할 여유가 있음을 의미
		cnt++;
		Union(par, par - 1);
	}

	cout << cnt << endl;


	return 0;
}