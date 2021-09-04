#include <iostream>
using namespace std;

int main() 
{
	int a, b, c, d;					//던진 윷들의 상태
	int sum = 0;					//1의 갯수의 합

	for (int i = 0; i < 3; i++)
	{
		cin >> a >> b >> c >> d;

		sum = a + b + c + d;

		switch (sum)
		{
		case 4:
			cout << 'E' << endl;
			break;

		case 3:
			cout << 'A' << endl;
			break;

		case 2:
			cout << 'B' << endl;
			break;

		case 1:
			cout << 'C' << endl;
			break;

		case 0:
			cout << 'D' << endl;
			break;
		}
	}

	return 0;
}