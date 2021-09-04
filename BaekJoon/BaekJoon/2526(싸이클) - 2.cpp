#include <iostream>
using namespace std;

int main()
{
	int n, p;						//n : 처음 출력하는 숫자, p : 나누는 수
	int next;						//현재의 값
	int cnt = 0;					//반복되는 수의 개수
	int arr[1001] = { 0, };			//반복되는 값을 거르기 위한 배열 -> n<=1000이므로 배열 범위 필요!

	cin >> n >> p;

	next = n;

	arr[n]++;						//시작하는 값도 세워줌

	while (1)
	{
		next = next * n % p;

		arr[next]++;

		if (arr[next] > 2)			//탈출조건 -> 확실하게 2번 이상 반복되는 경우만 탈출!
			break;
	}

	for (int i = 0; i < p; i++)
		if (arr[i] > 1)
			cnt++;

	cout << cnt << endl;


	return 0;
}