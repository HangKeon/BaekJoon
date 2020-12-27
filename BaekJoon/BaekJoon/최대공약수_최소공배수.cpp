#include <iostream>
using namespace std;

int main()
{
	int a, b;										//입력 받을 두 수
	int gcm, lcm;									//최대공약수, 최소공배수
	int div, quo, rest;								//나눠지는 값, 몫, 나머지

	cin >> a >> b;

	div = a;
	quo = b;

	while(1)
	{
		quo = a / b;
		rest = a % b;

		if (rest == 0)
		{
			gcm = b;
			lcm = (a*b) / gcm;

			cout << "최대공약수 : " << gcm << endl;
			cout << "최소공배수 : " << lcm << endl;
			break;
		}

		a = b;
		b = rest;
	} 

	


	return 0;
}