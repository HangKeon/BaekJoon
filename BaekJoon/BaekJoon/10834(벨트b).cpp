#include <iostream>
using namespace std;

int main()
{
	int m, a, b;
	int count = 1;

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		count = (count / a)*b;
	}

	cout << count << endl;





	return 0;
}