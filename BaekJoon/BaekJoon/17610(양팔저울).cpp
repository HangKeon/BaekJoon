#include <iostream>
#include <algorithm>
using namespace std;

int k;							//추의 개수
int sum = 0;					//모든 추의 무게의 합
int g[14];						//추의 무게를 저장할 배열
int visited[200000 * 13 + 1];	//나올 수 있는 무게들을 모두 표현 -> 1 : 만들 수 있는 무게, 0 : 만들 수 없는 무게

void dfs(int c, int result)		//dfs(추의 종류의 개수, 만들 수 있는 추의 무게)
{
	if (c > k)					//탈출조건
		return;

	if (c == k)	
		if(result >= 1)				//문제에서 1 ~ sum까지라고 함
			visited[result] = 1;	//방문처리

	dfs(c + 1, abs(result - g[c]));
	dfs(c + 1, result);
	dfs(c + 1, result + g[c]);
}

int main()
{
	int cnt = 0;				//측정이 가능한 경우

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> g[i];
		sum += g[i];
	}


	dfs(0, 0);

	for (int i = 1; i <= sum; i++)	
		if (!visited[i])
			cnt++;

	cout << cnt << endl;

	return 0;
}