#include <iostream>
using namespace std;

int main()
{
	int n, k;							//n = 태우고 있는 승객 수, k = 정류장 수
	int test;							//테스트 케이스 수
	int arr[31];
	arr[1] = 1;
	
	cin >> test;

	for (int i = 1; i <= test; i++)
	{
		cin >> k;
		for (int j = 1; j < k; j++)
		{
			arr[j + 1] = 2 * arr[j] + 1;
		}
		cout << arr[k] << endl;

	}

	return 0;
}