#include <iostream>
using namespace std;
//세그먼트 트리

#define MAX 1000000
#define ll long long

long long arr[MAX + 1];				//주어진 배열
long long tree[MAX * 4 + 1];			//구간 합 트리

ll init(ll s, ll e, ll node)	//구간 합 트리 만드는 함수 -> init(시작 인덱스, 끝 인덱스, 구하는 노드)
{
	if (s == e)						//리프 노드인 경우 -> 탈출 조건
		return tree[node] = arr[s];	

	ll mid = (s + e) / 2;

	return tree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);	//왼쪽 자식 노드 + 오른쪽 자식 노드
}

ll sum(ll s, ll e, ll node, ll l, ll r)	//구간 합 구하는 함수 ->sum(시작 인덱스, 끝 인덱스, 구하는 노드, 구간 합 범위)
{
	if (l > e || r < s)				//범위 밖에 있는 경우
		return 0;

	if (l <= s && e <= r)			//범위 안에 있는 경우
		return tree[node];

	ll mid = (s + e) / 2;

	return sum(s, mid, node * 2, l, r) + sum(mid + 1, e, node * 2 + 1, l, r);	//왼쪽 자식 노드 + 오른쪽 자식 노드
}

//update(시작 인덱스, 끝 인덱스, 구하는 노드 번호, 수정하려는 노드 번호, 수정할 값의 차이)
void update(ll s, ll e, ll node, ll idx, ll val)
{
	if (idx < s || idx>e)			//수정하려는 인덱스가 범위 밖에 있는 경우
		return;

	tree[node] += val;				//수정할 값 차이를 더함

	if (s == e)						//탈출 조건 -> 범위가 1인 리프 노드
		return;

	ll mid = (s + e) / 2;

	update(s, mid, node * 2, idx, val);				//왼쪽 자식 노드
	update(mid + 1, e, node * 2 + 1, idx, val);		//오른쪽 자식 노드
}

int main()
{
	long long n, m, k;				//n : 수의 개수, m : 변경이 일어나는 횟수, k : 구간의 합 구하는 횟수
	long long a, b, c;				//a : 1 -> b번째 수를 c로 바꿈
									//    2 -> b ~ c번째 수까지의 합을 출력

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(1, n, 1);					//구간 합 트리 완성

	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;

		if (a == 1)								//a == 1이면
		{
			update(1, n, 1, b, c - arr[b]);		//b번째 수를 c로 바꿈
			arr[b] = c;							//arr 값을 c로 바꿔줘야 한다 -> 안 한다면 c가 이전과 같은 값이 나올 때 값이 바뀌지 않아 문제가 발생!
		}
		else if(a == 2)							//a == 2이면
			cout << sum(1, n, 1, b, c) << "\n";	//b ~ c번째 수까지의 합을 출력
	}

	return 0;
}