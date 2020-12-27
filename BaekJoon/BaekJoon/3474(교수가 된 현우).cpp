#include <iostream>
using namespace std;

int fac(int);

int main()
{
	int t;
	int *input;
	int *output;
	int cnt = 0;									//0ÀÇ °³¼ö
	int value = 0, k = 0;

	cin >> t;
	input = new int[t];
	output = new int[t];
	for (int i = 0; i < t; i++)
		output[i] = { 0, };

	for (int i = 0; i < t; i++)
	{
		cin >> input[i];
		value = fac(input[i]);

		for (int j = 0;; j++)
		{
			if (value % 10 == 0)
			{
				cnt++;
				value /= 10;
			}
			else
				break;
		}
		output[i] += cnt;
		cnt = 0;
		value = 0;
	}

	for (int i = 0; i < t; i++)
		cout << output[i] << endl;


	return 0;
}

int fac(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * fac(n - 1);
}