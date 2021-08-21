#include <iostream>
using namespace std;

int main()
{
	int n;						//Ä­ÀÇ ¼ö
	int a = 1;

	cin >> n;

	while (a * 2 <= n)			//2ÀÇ °ÅµìÁ¦°ö
	{
		a *= 2;
	}

	cout << a << endl;

	return 0;
}