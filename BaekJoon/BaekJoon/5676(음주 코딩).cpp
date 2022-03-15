#include <iostream>
#include <string>
using namespace std;

int arr[100001];					//주어진 배열
int tree[4 * 100000 + 1];			//구간 곱 트리

int init(int s, int e, int node)	//구간 곱 트리 만드는 함수 -> (시작 인덱스, 끝 인덱스, 구하는 노드 번호)
{
	if (s == e)						//리프 노드인 경우 -> 탈출 조건
		return tree[node] = arr[s];

	int mid = (s + e) / 2;

	//tree = 왼쪽 자식 노드 * 오른쪽 자식 노드
	return tree[node] = init(s, mid, node * 2)*init(mid + 1, e, node * 2 + 1);
}

//mul(시작 인덱스, 끝 인덱스, 구하는 노드 번호, 구간 곱 범위)
int mul(int s, int e, int node, int l, int r)	//구간 곱을 구하는 함수
{
	if (l > e || r < s)				//범위 밖에 있는 경우
		return 1;

	if (l <= s && e <= r)			//범위 안에 있는 경우
		return tree[node];

	int mid = (s + e) / 2;

	//왼쪽 자식 노드 * 오른쪽 자식 노드
	return mul(s, mid, node * 2, l, r)*mul(mid + 1, e, node * 2 + 1, l, r);
}

//update(시작 인덱스, 끝 인덱스, 구하는 노드 번호, 수정하려는 노드 번호, 수정할 값)
int update(int s, int e, int node, int idx, int val)
{
	if (idx<s || idx>e)				//수정하려는 인덱스가 범위 밖에 있는 경우
		return tree[node];

	if (s == e)						//리프 노드인 경우 -> 탈출 조건
		return tree[node] = val;

	int mid = (s + e) / 2;

	//tree = 왼쪽 자식 노드 * 오른쪽 자식 노드
	return tree[node] = update(s, mid, node * 2, idx, val)*update(mid + 1, e, node * 2 + 1, idx, val);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;						//n : 수열의 크기, k : 게임 라운드 수
	char c;							//C : 변경, P : 곱셈
	int a, b;						//입력하는 값 -> C,P에 따라 의미가 다름 

	while (cin >> n >> k)
	{
		string str = "";

		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];

			//오버플로우 발생을 막기 위해 1,-1만 사용!
			if (arr[i] > 0)
				arr[i] = 1;
			else if (arr[i] < 0)
				arr[i] = -1;
		}

		init(1, n, 1);					//구간 곱 트리 만들기

		for (int i = 0; i < k; i++)
		{
			cin >> c >> a >> b;

			if (c == 'C')				//변화
			{
				//오버플로우 발생을 막기 위해 1,-1만 사용!
				if (b > 0)
					b = 1;
				else if (b < 0)
					b = -1;

				update(1, n, 1, a, b);
				arr[a] = b;
			}
			else if (c == 'P')			//곱셈
			{
				int temp = mul(1, n, 1, a, b);

				if (temp == 0)
					//cout << 0;
					str += '0';
				else if (temp > 0)
					//cout << '+';
					str += '+';
				else
					//cout << '-';
					str += '-';
			}
		}
		cout << str<<"\n";
	}

	return 0;
}