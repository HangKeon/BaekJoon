#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	long long int total = 1;

	cin >> a >> b >> c;

	for (int i = 0; i < b; i++)
	{
		total *= a;
		
	}
	total %= c;
	
	cout << "Ãâ·Â : " << total << endl;




	return 0;
}

//ÇÏ