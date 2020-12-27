#include <iostream>
using namespace std;

int bottle[200001] = { 0, };		//물의 무게를 저장 -> 물의 무게가 x라면 bottle[x]=1을 저장
int arr[14] = { 0, };				//추의 무게를 저장할 배열
int k;								//서로 무게가 다른 추의 개수

void dfs(int x, int s)				//dfs(bottle의 인덱스,추의 합)
{
	if (x == k)						//bottle의 인덱스 = 추의 개수
	{
		if (s >= 1)					//추의 무게가 1 이상이라면
			bottle[s] = 1;			//bottle에 1을 넣어 가능한 무게를 체크한다.
	}
	else
	{
		//bottle의 인덱스를 1씩 증가
		dfs(x + 1, s);					//이전의 추의 무게를 물의 무게와 그대로 비교!
		dfs(x + 1, s + arr[x]);			//추의 무게를 arr[x]만큼 증가
		dfs(x + 1, s - arr[x]);			//물의 무게를 arr[x]만큼 증가
	}

}

int main()
{

	int cnt = 0;					//양팔 저울을 한 번만 이용하여서는 측정이 불가능한 경우
	int s = 0, x;					//s = 모든 추의 합, x = 물의 무게


	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		s += arr[i];
	}

	dfs(0, 0);

	for (int i = 1; i <= s; i++)		//bottle=0인 경우를 찾아서 cnt를 1씩 증가!
		if (bottle[i] == 0)
			cnt++;

	cout << cnt << endl;


	return 0;
}