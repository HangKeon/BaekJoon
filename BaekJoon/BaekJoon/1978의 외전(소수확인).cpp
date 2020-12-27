#include <iostream>
using namespace std;
//입력한 수가 소수인지 확인.

int main()
{
	int a=0, n=0;				//n=입력하는 수, 즉 소수인지 확인 받는 수.

	cin >> n;

	for (a = 2; a < n; a++)
	{
		if (n%a == 0)
		{
			cout << n << "은 소수가 아님." << endl;
			break;
		}
	}

	if (a == n)
		cout << a << " 는 소수" << endl;

	

	return 0;
}

//하