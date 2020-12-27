#include <iostream>
using namespace std;

int main()
{
	int a[10], num = 0, v;
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < 10; i++)
	{
		if (a[i] < 0 && a[i] > 1000)
		{
			break;
		}
	}

	for (int i = 0; i < 10; i++)
		a[i] = a[i] % 42;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (a[i] == a[j])
				num++;
		}
	}
	v = 10 - num;
	cout << v << endl;

	return 0;
}

//Сп