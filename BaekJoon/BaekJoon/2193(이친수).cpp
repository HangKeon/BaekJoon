#include <iostream>
using namespace std;

int main()
{
	int N;												//N = 이친수의 자리 수
	long long int arr[91];								//N = 47일 때 int 범위 초과! 따라서 long long int 를 사용!

	cin >> N;

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= N; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	cout << arr[N] << endl;

	return 0;
}

//중	->	방법을 알면 하