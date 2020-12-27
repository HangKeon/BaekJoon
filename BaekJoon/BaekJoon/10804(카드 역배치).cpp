#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[21];					//1~20까지 저장된 배열
	int a, b;						//a : 시작 부분, b : 끝 부분

	for (int i = 1; i <= 20; i++)
		arr[i] = i;

	for (int i = 0; i < 10; i++)
	{
		cin >> a >> b;

		reverse(arr + a, arr + b + 1);
	}

	for (int i = 1; i <= 20; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}