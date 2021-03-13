#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b)	//끝나는 값을 기준으로 오름차순 만드는 함수
{
	return (a.second < b.second);
}

int main()
{
	int n;						//회의의 수
	int a, b;					//회의 시작 시간, 끝나는 시간
	int cnt = 0;				//회의의 최대 횟수
	int Min;					//아직 정해지지 않은 시간표 중 가장 작은 끝나는 시간 
	vector<pair<int, int> > v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());					//우선 v의 first를 기준으로 오름차순
	sort(v.begin(), v.end(), comp);				//그리고 나서 v의 second를 기준으로 오름차순
	//sort(v.begin(), v.end(), greater<>());
	//sort(v.rbegin(), v.rend());

	Min = v[0].second;
	cnt++;

	for (int i = 1; i < n; i++)
	{
		if (v[i].first >= Min)					//새로 회의를 시작할 시간 >= 이전 회의의 끝나는 시간
		{
			Min = v[i].second;
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}

//반례
//3
//2 2
//1 2
//2 3