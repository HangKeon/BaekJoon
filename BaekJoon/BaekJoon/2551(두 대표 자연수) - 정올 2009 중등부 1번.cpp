#include <iostream>
#include <algorithm>
using namespace std;

long long add[5000001];					//add[n] : 0~n번지의 v의 누적합을 저장
long long mul[5000001];					//mul[n] : 0~n번지의 v^2의 누적합을 저장
int arr[5000001];						//입력할 값을 저장할 배열

int main()
{
	cin.tie(0);

	int n;								//자연수의 개수
	long long sum = 5e10 + 1;			//가장 작은 차이의 합
	long long temp;						//차이의 합
	int ans;							//sum에 해당하는 arr값

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	sort(arr + 1, arr + 1 + n);					//답에 작은 값을 순서로 출력하기 위해 정렬

	for (int i = 1; i <= n; i++)				//1번 방식 구하기
	{
		if (i == 1)								//제일 처음 값을 위해서 사용
		{
			add[i] = arr[i];
			mul[i] = arr[i] * arr[i];
		}
		else							//나머지의 누적합을 구하기 -> for문을 1개만 사용!
		{
			add[i] = add[i - 1] + arr[i];
			mul[i] = mul[i - 1] + arr[i] * arr[i];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		temp = (long long)arr[i] * (i - 1) - add[i - 1] + (add[n] - add[i]) - (long long)arr[i] * (n - i);	//2548번 참조

		if (sum > temp)
		{
			sum = temp;
			ans = arr[i];	
		}
	}

	cout << ans << ' ';

	sum = 5e14 + 1;																//초기화

	for (int i = 1; i <= 10000; i++)											//2번 방식 구하기
	{
		temp = mul[n] - (long long)2 * add[n] * i + (long long)i * i * n;		//인수분해의 합

		if (sum > temp)
		{
			sum = temp;
			ans = i;
		}
	}

	cout << ans << endl;


	return 0;
}