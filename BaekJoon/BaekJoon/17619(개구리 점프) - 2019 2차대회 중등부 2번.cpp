#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct info
{
	int x1, x2, idx;				//x1,x2 : 통나무 좌표, idx : 통나무 번호
}info;

int parent[100001];					//부모 통나무 번호
vector<info> v;

int find(int x)
{
	if (parent[x] == x)				//통나무 번호 == x
		return x;

	return parent[x] = find(parent[x]);
}

void unione(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}


bool cmp(const info & a, const info & b)
{
	return a.x1 < b.x1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, q;						//n : 통나무의 개수, q : 질문의 개수
	int x1, x2, y;					//통나무 좌표
	int a, b;						//연결되어 있는지 물어볼 통나무

	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		cin >> x1 >> x2 >> y;

		v.push_back({ x1,x2,i });		//여기서 알아야 하는 것은 v[0]부터 채워진다는 점이다

		parent[i] = i;					//처음에는 자기 자신을 가리킴
	}

	sort(v.begin(), v.end(), cmp);			//오름차순 정렬

	for (int i = 0, j = 1; i < n && j < n;)
	{

		//j통나무의 앞 좌표 <= i통나무의 뒷 좌표
		if (v[j].x1 <= v[i].x2)
		{
			unione(v[i].idx, v[j].idx);
			j++;
		}
		else
			i++;

	}

	for (int i = 0; i < q; i++)
	{
		cin >> a >> b;

		//cout << findParent(a, b) << endl;		//시간초과 남
		if (find(a) == find(b))
			cout << "1\n";
		else
			cout << "0\n";
	}
	
	return 0;
}