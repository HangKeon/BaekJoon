#include <iostream>
using namespace std;

int main()
{
	int a, b, c, n;					//a,b,c : 한 방에 머물 수 있는 인원수, n : 전체 인원 수
	int min;						//방에 머무는 최소 인원수

	cin >> a >> b >> c >> n;

	min = n % a;

	if (n%b < min)
		min = n % b;

	if (n%c < min)
		min = n % c;

	cout << min << endl;

	return 0;
}