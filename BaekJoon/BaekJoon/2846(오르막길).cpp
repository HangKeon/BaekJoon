#include <iostream>
using namespace std;

int main()
{
	int result=0;
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			result = i*j;
			cout << i<<" x "<<j<<" = "<<result<<endl;
		}
		cout << endl;
	}




	return 0;
}

//го