#include <iostream>
#include <algorithm>
using namespace std;

int cnt[3001] = { 0, };				//내가 먹은 초밥의 갯수를 저장할 배열
int ans = 0;						//현재 먹은 초밥 종류

void push(int a)					//초밥을 먹었을 경우
{
	if (!cnt[a])					//아직 먹지 않았으면
		ans++;						//먹을 것이므로 초밥 갯수를 1 증가
	cnt[a]++;						//먹은 것으로 처리하기 위해 1 증가
}

void pop(int a)						//초밥을 먹지 않는 경우 -> 이미 먹은 것으로 취급했지만 안 먹은 것으로 바꾸는 경우
{
	cnt[a]--;						//먹었다고 처리했으므로 1을 빼서 안 먹은 것으로 다시 바꾼다.

	if (!cnt[a])					
		ans--;
}

int main()
{
	int n, d, k, c;				//n : 초밥 벨트에 놓인 접시 수, d : 초밥의 가짓수, k : 연속해서 먹는 접시 수, c : 쿠폰 번호
	int arr[60001];				//초밥 종류 -> 원형이므로 한 번 돌았다고 가정!
	int val = 0;				//먹은 초밥의 가짓수의 최댓값을 저장할 배열

	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < k - 1; i++)		//먼저 쿠폰부터 처리해줄 것이기에 이만큼을 더 추가해주어야 한다.
		arr[n + i] = arr[i];

	push(c);						//쿠폰부터 처리하자

	for (int i = 0; i < k - 1; i++)	//쿠폰으로 음식을 먼저 하나 먹은 것으로 취급하여 k-1로 만큼 더 추가!
		push(arr[i]);

	for (int i = 0; i < n; i++)		//이제 하나씩 전부 확인한다
	{
		push(arr[i + k - 1]);		//
		val = max(val, ans);
		pop(arr[i]);
	}

	cout << val << endl;

	return 0;
}