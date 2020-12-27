#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> v;				//듣도 못한 사람들의 명단을 저장
	vector<string> r;				//v와 보도 못한 사람의 명단을 비교해 저장
	int n, m;						//n = 들도 못한 사람의 수, m = 보도 못한 사람의 수
	int j = 0;

	cin >> n >> m;

	v.resize(n);					//v의 크기를 n으로 변경하고 확장되는 공간의 값을 기본값으로 초기화 한다

	for (int i = 0; i < n; i++)		//n을 입력
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());		//v를 오름차순으로 정렬

	string s;

	for (int i = 0; i < m; i++)
	{
		cin >> s;

		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] == s)				//만약 v와 s가 같다면
			{
				r.push_back(s);			//r에 s를 대입
			}
		}

	}

	sort(r.begin(), r.end());		//v를 오름차순으로 정렬

	cout << r.size() << endl;
	for (int i = 0; i < r.size(); i++)
		cout << r[i] << endl;


	return 0;
}