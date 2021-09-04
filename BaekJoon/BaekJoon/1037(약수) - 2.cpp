#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a;						//약수의 개수 
	int arr[51];				//n의 진짜 약수

	cin >> a;

	for (int i = 0; i < a; i++)
		cin >> arr[i];

	sort(arr, arr + a);

	cout << arr[0] * arr[a - 1] << endl;

	return 0;
}