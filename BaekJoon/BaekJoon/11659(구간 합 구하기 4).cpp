#include <iostream>
using namespace std;
//세그먼트 트리로 품(구간합도 가능!).

int arr[100001];					//주어진 배열
int tree[4 * 100000];				//구간 합 트리

int init(int s, int e, int node)	//구간 합 트리 만듦 -> init(시작 인덱스, 끝 인덱스, 구해야 하는 노드 번호)
{
	if (s == e)						//탈출조건 -> 리프노드인 경우
		return tree[node] = arr[s];

	int mid = (s + e) / 2;

	return tree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);	//왼쪽 노드 + 오른쪽 노드
}

int sum(int s, int e, int node, int l, int r)	//sum(시작 인덱스, 끝 인덱스, 구하는 노드 번호, 구간 합 범위)
{
	if (l > e || r < s)							//범위 밖에 있는 경우
		return 0;

	if (l <= s && e <= r)						//범위 안에 있는 경우
		return tree[node];

	int mid = (s + e) / 2;

	return sum(s, mid, node * 2, l, r) + sum(mid + 1, e, node * 2 + 1, l, r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;						//n : 수의 개수, m : 구해야 하는 횟수
	int a, b;						//구해야 하는 구간의 범위

	cin >> n >> m;

	for (int i = 1; i <= n; i++)	//i=1이 아니면 범위에 문제가 생긴다.
		cin >> arr[i];

	init(0, n, 1);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		cout << sum(0, n, 1, a, b) << "\n";
	}

	return 0;
}