#include <iostream>
using namespace std;

int main()
{
	//int measure[101];									//약수를 저장할 배열
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0)
			cout << i << ' ';
	}
	cout << endl;



	return 0;
}