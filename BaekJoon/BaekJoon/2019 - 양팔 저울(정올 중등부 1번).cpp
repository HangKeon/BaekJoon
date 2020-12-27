#include <iostream>
using namespace std;

int bottle[2600001] = { 0, };		//물의 무게를 저장 -> 물의 무게가 x라면 bottle[x]=1을 저장

int main()
{

	int cnt = 0;						//양팔 저울을 한 번만 이용하여서는 측정이 불가능한 경우
	int s = 0;							//s = 모든 추의 합
	int arr[14] = { 0, };				//추의 무게를 저장할 배열
	int brr[14] = { 0, };				//추가 어디에 사용되었는지 저장 -> 0 : 사용X / 1 : 추에 무게를 추가 / 2 : 물통에 무게를 추가
										//brr은 3진수로 생각할 수 있다.
	int k;								//서로 무게가 다른 추의 개수
	int w = 0;							//현재 추의 무게



	cin >> k;

	for (int i = 1; i <= k; i++)
	{
		cin >> arr[i];
		s += arr[i];
	}

	while (brr[0] != 1)					//brr[0]==1인 경우는 arr을 이용해 만들 수 있는 모든 경우를 다 확인한 것이다.
	{
		brr[k] += 1;					//brr의 값을 계속1씩 증가 -> 모든 경우를 확인!

		for (int i = k; i >= 1; i--)		//brr은 0,1,2만 사용하므로 3진수와 비슷하다. 
		{									//즉, 000,001,002,010,011, ... ,220,221,222까지 모두 확인할 수 있다
			if (brr[i] == 3)
			{
				brr[i - 1] += 1;
				brr[i] = 0;
			}
		}

		for (int i = 1; i <= k; i++)
		{
			if (brr[i] == 1)						//추가 있는 쪽에 무게를 추가하는 경우
				w += arr[i];						//w에 arr을 더한다
			else if (brr[i] == 2)					//물통쪽에 무게를 추가하는 경우
				w -= arr[i];						//w에서 arr을 뺀다.
		}

		if (w > 0)
			bottle[w]++;

		w = 0;										//다시 반복하기 위해 w를 0으로 초기화
	}

	for (int i = 1; i <= s; i++)						//bottle = 0인 것의 개수를 cnt에 저장 -> k개의 추를 이용해서 만들 수 없는 물의 무게의 개수
		if (bottle[i] == 0)
			cnt++;

	cout << cnt << endl;

	return 0;
}