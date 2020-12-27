#include <iostream>
using namespace std;

int main()
{
	int n, cnt = 1;
	cin >> n;

	while (n != 1)
	{
		if (n % 2 == 0)				//Â¦¼ö
			n /= 2;
		else						//È¦¼ö
			n = 3 * n + 1;
		cnt++;
	}

	cout << cnt << endl;

	return 0;
}