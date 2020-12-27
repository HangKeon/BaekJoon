#include <iostream>
using namespace std;

int arr[100001];

void dfs(int s, int e)			//dfs(현재 노드, 끝 노드)
{
	if (s == e)					//탈출조건
		return;

	if (s == e - 1)				//현 노드 == 마지막 후위 순회 노드
	{
		cout << arr[s] << endl;
		return;
	}

	int k = s + 1;

	while (1)
	{
		if (!(k < e && arr[k] < arr[s]))
			break;

		k++;
	}

	dfs(s + 1, k);
	dfs(k, e);

	cout << arr[s] << endl;
}

int main()
{
	int n;						//전위 순회 입력
	int idx = 0;				//전위 순회 값을 저장하는 인덱스 -> 개수

	while (cin >> n)
	{
		arr[idx++] = n;
	}

	dfs(0, idx);

	return 0;
}