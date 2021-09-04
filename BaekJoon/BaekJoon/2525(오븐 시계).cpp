#include <iostream>
using namespace std;

int main() 
{
	int a, b, c;				//a : 시, b : 분, c : 요리하는데 필요한 시간(분)

	cin >> a >> b >> c;

	b += c;

	c = b / 60;					//60분이 넘을 경우 시간을 임시로 담음.
	b %= 60;					//60분으로 나눈 나머지를 저장!
	a += c;

	if (a > 23)
		a %= 24;

	cout << a << ' ' << b << endl;



	return 0;
}