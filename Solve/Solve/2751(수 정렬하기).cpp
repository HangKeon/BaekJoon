#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;						//수의 개수
	int t;						//임시로 입력할 숫자
	vector<int> v;				//숫자를 저장

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t;

		v.push_back(t);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}