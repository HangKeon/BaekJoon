#include <iostream>
using namespace std;

int main()
{
	int dec, twv, hex;						//10진수, 12진수, 16진수를 저장할 변수

	for (int i = 1000; i <= 9999; i++)
	{
		dec = 0, twv = 0, hex = 0;

		for (int j = i; j > 0; j /= 10)			//10진수 자리 수 합
			dec += j % 10;

		for (int j = i; j > 0; j /= 12)			//12진수 자리 수 합
			twv += j % 12;

		for (int j = i; j > 0; j /= 16)			//16진수 자리 수 합
			hex += j % 16;

		if (dec == twv && dec == hex)
			cout << i << endl;
	}

	return 0;
}