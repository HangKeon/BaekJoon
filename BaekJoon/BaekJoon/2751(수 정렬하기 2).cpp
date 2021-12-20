#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;							//갯수
	int t;							//입력할 숫자
	vector<int> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		cout << v[i] << "\n";

	return 0;
}