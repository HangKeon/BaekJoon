#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;						//���� ����
	int a, b;
	vector<pair<int, int> > p;	//��ǥ

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		p.push_back({ a,b });
	}

	sort(p.begin(),p.end());

	for (int i = 0; i < n; i++)
		cout << p[i].first << ' ' << p[i].second << "\n";

	return 0;
}