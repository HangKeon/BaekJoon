#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100001];				//주어진 배열
long long tree[4 * 100000 + 1];		//구간 트리

long long init(int s, int e, int node)	//구간 트리 만드는 함수 -> init(시작 인덱스, 끝 인덱스, 구하는 노드)
{
	if (s == e)						//리프 노드인 경우 -> 탈출 조건
		return tree[node] = arr[s];

	int mid = (s + e) / 2;

	return tree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);	//왼쪽 자식 노드 + 오른쪽 자식 노드
}

long long sum(int s, int e, int node, int l, int r)	//구간 합 구하는 함수 -> sum(시작 인덱스, 끝 인덱스, 구하는 노드 번호, 구간 합 범위)
{
	if (l > e || r < s)				//범위 밖에 있는 경우
		return 0;

	if (l <= s && e <= r)			//범위 안에 있는 경우
		return tree[node];

	int mid = (s + e) / 2;

	return sum(s, mid, node * 2, l, r) + sum(mid + 1, e, node * 2 + 1, l, r);
}

//update(시작 인덱스, 끝 인덱스, 구하는 노드 번호, 수정하려는 노드 번호, 수정할 값의 차이)
void update(int s, int e, int node, int idx, long long val)
{
	if (idx<s || idx>e)				//수정하려는 인덱스가 범위 밖에 있는 경우
		return;

	tree[node] += val;

	if (s == e)						//리프 노드인 경우 -> 탈출 조건
		return;

	int mid = (s + e) / 2;

	update(s, mid, node * 2, idx, val);				//왼쪽 자식 노드
	update(mid + 1, e, node * 2 + 1, idx, val);		//오른쪽 자식 노드
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;					//n : 수의 개수, m : 턴의 개수
	int x, y, a, b;				//x~y까지의 합을 구해라 + a번째 수를 b로 바꿔라

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(1, n, 1);

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> a >> b;

		int _x = min(x, y);
		int _y = max(x, y);

		cout << sum(1, n, 1, _x, _y) << "\n";

		update(1, n, 1, a, b - arr[a]);

		arr[a] = b;								//arr[a]를 b로 바꿔줘야 다음 번 계산에 문제가 되지 않는다.
	}

	return 0;
}