#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;						//���� ����
	int t;						//�ӽ÷� �Է��� ����
	vector<int> v;				//���ڸ� ����

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