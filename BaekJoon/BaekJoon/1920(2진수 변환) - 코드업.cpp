#include <iostream>
using namespace std;

void two(int n)
{
	int r = n % 2;

	if (n <= 1)
		cout << n;
	else
	{
		two(n / 2);
		cout << r;
	}
}

int main()
{
	int n;

	cin >> n;

	two(n);

	return 0;
}