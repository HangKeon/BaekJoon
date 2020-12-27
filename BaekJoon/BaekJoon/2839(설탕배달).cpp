#include <iostream>
using namespace std;

int main()
{
	int n, cnt = 0;						//n = ¼³ÅÁÀÇ ¹«°Ô, cnt = ºÀÁöÀÇ ¼ö

	cin >> n;

	while (n>0)
	{
		if (n % 5 == 0)
		{
			cnt++;
			n -= 5;
		}
		else if (n % 3 == 0)
		{
			cnt++;
			n -= 3;
		}
		else if (n >= 5)
		{
			cnt++;
			n -= 5;
		}
		else if (n >= 3)
		{
			cnt++;
			n -= 3;
		}
		else
		{
			cout << "-1" << endl;
			return 0;
		}
	}

	cout << cnt << endl;



	return 0;
}