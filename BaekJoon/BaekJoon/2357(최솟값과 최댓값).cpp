#include <iostream>
#include <algorithm>
using namespace std;
//세그먼트 트리

int arr[100001];						//주어진 배열
int min_tree[4 * 100000 + 1];			//최소 구간 트리
int max_tree[4 * 100000 + 1];			//최대 구간 트리

int min_init(int s, int e, int node)	//최소 구간 트리 만드는 함수 -> min_init(시작 인덱스, 끝 인덱스, 구하는 노드)
{
	if (s == e)							//리프 노드라면 -> 탈출 조건
		return min_tree[node] = arr[s];

	int mid = (s + e) / 2;

	return min_tree[node] = min(min_init(s, mid, node * 2), min_init(mid + 1, e, node * 2 + 1));
}

int max_init(int s, int e, int node)	//최대 구간 트리 만드는 함수 -> max_init(시작 인덱스, 끝 인덱스, 구하는 노드)
{
	if (s == e)							//리프 노드라면 -> 탈출 조건
		return max_tree[node] = arr[s];

	int mid = (s + e) / 2;

	return max_tree[node] = max(max_init(s, mid, node * 2), max_init(mid + 1, e, node * 2 + 1));
}

int min_find(int s, int e, int node, int l, int r)	//최소 찾는 함수 -> min_find(시작 인덱스, 끝 인덱스, 구하는 노드, 범위)
{
	if (l > e || r < s)					//범위 밖에 있는 경우
		return 1e9;

	if (l <= s && e <= r)				//범위 안에 있는 경우
		return min_tree[node];

	int mid = (s + e) / 2;

	return min(min_find(s, mid, node * 2, l, r), min_find(mid + 1, e, node * 2 + 1, l, r));
}

int max_find(int s, int e, int node, int l, int r)	//최대 찾는 함수 -> min_find(시작 인덱스, 끝 인덱스, 구하는 노드, 범위)
{
	if (l > e || r < s)					//범위 밖에 있는 경우
		return -1e9;

	if (l <= s && e <= r)				//범위 안에 있는 경우
		return max_tree[node];

	int mid = (s + e) / 2;

	return max(max_find(s, mid, node * 2, l, r), max_find(mid + 1, e, node * 2 + 1, l, r));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;							//n : 정수의 개수, m : 범위의 개수
	int a, b;							//범위

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	min_init(1, n, 1);						//최소 구간 트리 완성
	max_init(1, n, 1);						//최대 구간 트리 완성

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		cout << min_find(1, n, 1, a, b) << ' ' << max_find(1, n, 1, a, b) << "\n";
	}

	return 0;
}