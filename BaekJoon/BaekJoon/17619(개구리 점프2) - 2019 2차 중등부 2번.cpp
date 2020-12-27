#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

//시간초과

vector<pair<pair<long long,long long>, int> > v[100001];	//통나무의 크기를 저장
int parent[100001];								//부모 통나무 번호 -> 처음에는 자기 자신을 저장!

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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, q;						//n : 통나무의 개수, q : 질문의 개수
	long long x1, x2, y;					//통나무 좌표
	int a, b;						//연결되어 있는지 물어볼 통나무

	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		cin >> x1 >> x2 >> y;

		v[i].push_back({ { x1, x2 }, i });	//통나무 시작점(x1), 통나무 끝점(x2), 통나무 번호
	}

	sort(v + 1, v + 1 + n);					//통나무 시작점 값으로 정렬

	for (int i = 1; i <= n; i++)
		parent[v[i].front().second] = v[i].front().second;

	for (int i = 1; i < n; i++)
	{
		//i통나무의 앞 좌표 <= (i+1)통나무의 앞 좌표 <= i통나무의 뒷 좌표
		if (v[i].front().first.first <= v[i + 1].front().first.first && v[i].front().first.second >= v[i + 1].front().first.first)
		{
			unione(v[i].front().second, v[i + 1].front().second);
		}
	}

	for (int i = 0; i < q; i++)
	{
		cin >> a >> b;

		if (find(a) == find(b))
			cout << "1\n";
		else
			cout << "0\n";
	
	}


	return 0;
}