#include <iostream>
#include <string>
using namespace std;

int main()
{
	char dish[51];
	int len, height = 10;

	cin >> dish;

	len = strlen(dish);

	for (int i = 1; i < len; i++)
	{
		if (dish[i - 1] == dish[i])
			height += 5;
		else
			height += 10;
	}

	cout << height << endl;


	return 0;
}