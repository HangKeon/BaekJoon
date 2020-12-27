#include <iostream>
using namespace std;

int main()
{
	int c[8], i=0;

	for (int i = 0; i < 8; i++)
		cin >> c[i];

		if (c[i] > c[i + 1]&& c[i+1] > c[i + 2]&& c[i+2] > c[i + 3]&& c[i+3] > c[i + 4]
			&& c[i + 4] > c[i + 5] && c[i + 5] > c[i + 6] && c[i + 6] > c[i + 7])
			cout << "descending\n";
		else if (c[i] < c[i + 1] && c[i + 1] < c[i + 2] && c[i + 2] < c[i + 3]
			&& c[i + 3] < c[i + 4]&& c[i + 4] < c[i + 5] && c[i + 5] < c[i + 6]
			&& c[i + 6] < c[i + 7])
			cout << "ascending\n";
		else
			cout << "mixed\n";
	
	return 0;
}

//го