#include <iostream>
using namespace std;

int main()
{
	int a, b, c;							//입력할 값
	int arr[10] = { 0, }, mul, r;			//arr = 0 ~ 9 까지의 수의 개수, mul = a*b*c, r = mul%10

	cin >> a >> b >> c;
	mul = a * b * c;

	for (int i = 0; mul != 0; i++)
	{
		r = mul % 10;
		mul /= 10;
		arr[r]++;
	}

	for (int i = 0; i < 10; i++)
		cout << arr[i] << endl;







	return 0;
}