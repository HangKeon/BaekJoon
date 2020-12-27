#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool comp(const string &s1, const string &s2)
{
	if (s1.size() == s2.size())
		return s1 < s2;

	return s1.size() < s2.size();
}

int main()
{
	vector<string> v;				//입력할 단어
	string str;
	int n;							//단어의 개수

	cin >> n;

	for (int i = 0; i < n; i++)		//단어 입력
	{
		cin >> str;
		v.push_back(str);
	}


	sort(v.begin(), v.end(), comp);		//정렬(오름차순)

	for (int i = 0; i < n; i++)
	{
		if (i != 0)						//중복제거
		{
			if (v[i - 1] == v[i])
				continue;
		}

		cout << v[i] << endl;
	}

	return 0;
}