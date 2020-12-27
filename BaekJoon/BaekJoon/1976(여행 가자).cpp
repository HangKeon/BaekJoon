#include <iostream>
#include <algorithm>
using namespace std;

int parent[201];

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

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main()
{
	int n, m;						//n : 도시의 수, m : 여행 계획에 속한 도시의 수
	int arr;
	int plan[1001];					//여행 계획

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr;

			if (arr)				//arr == 1인 경우
				Union(i, j);		//합집합
		}
	}

	for (int i = 1; i <= m; i++)
		cin >> plan[i];

	sort(plan, plan + m + 1);		//오름차순으로 저장해 제일 작은 노드 번호를 plan[1]에 저장

	arr = find(plan[1]);			//arr에 가장 작은 노드 번호를 미리 저장 -> 왜냐하면 여러 번 쓸 것인데 계속 함수를 부르면 비효율적이기 때문 

	for (int i = 2; i <= m; i++)
	{
		if (arr != find(plan[i]))
		{
			cout<<"NO\n";
			return 0;
		}
	}

	cout << "YES\n";


	return 0;
}