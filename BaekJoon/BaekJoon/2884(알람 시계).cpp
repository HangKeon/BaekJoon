#include <iostream>
using namespace std;

int main()
{
	int h, m;					//상근이가 설정한 알람시간(h시 m분)

	cin >> h >> m;

	

	if (m < 45)
	{
		h--;
		m += 60;
	}

	if (h < 0)
		h += 24;
	

	m -= 45;

	cout << h << ' ' << m << endl;


	return 0;
}