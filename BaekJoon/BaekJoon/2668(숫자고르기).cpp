#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;							//이루고 있는 번호
int arr[101];					//둘째 줄에 들어갈 번호를 저장할 배열 -> 인덱스는 첫째줄
int visited[101];				//방문
int result[101];				//사이클한 노드 저장
int idx = 0;

void dfs(int x, int y)			//dfs(현재 노드, 시작 노드)
{
	if (visited[x])				//만약 방문o 
	{
		if(x == y)				//현재 노드 = 시작노드->사이클!!
			result[idx++] = y;
	}
	else
	{
		visited[x] = 1;
		dfs(arr[x], y);
	}
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		dfs(i, i);
	}

	//sort(result, result + idx);

	cout << idx << endl;

	for (int i = 0; i < idx; i++)
		cout << result[i] << endl;

	return 0;
}