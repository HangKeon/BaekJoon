#include <iostream>
using namespace std;

int main()
{
	int n, len[81];					//n : 타일의 수, len[81] : 한 변의 길이

	cin >> n;

	len[1] = 1;
	len[2] = 1;

	for (int i = 3; i <= n; i++)
		len[i] = len[i - 1] + len[i - 2];

	cout << len[n] << endl;

	return 0;
}