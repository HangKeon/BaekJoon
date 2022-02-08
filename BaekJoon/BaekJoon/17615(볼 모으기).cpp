#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;							//볼의 총 갯수
	int sw = 0;						//옮겨야 할 색이 아닌 것이 나왔을 때 1로 바꿈.
	int cnt = 0;					//옮기는 공의 갯수
	int m = 2e9;					//옮기는 공의 최소 갯수
	string s;						//볼의 색깔

	cin >> n;

	cin >> s;

	for (int i = 0; i < n; i++)		//R을 왼쪽으로 모두 옮기는 경우
	{
		if (s[i] == 'B')
			sw = 1;

		if (sw && s[i] == 'R')
			cnt++;
	}

	sw = 0;
	if (cnt < m)
		m = cnt;
	cnt = 0;

	for (int i = n - 1; i >= 0; i--)	//R을 오른쪽으로 모두 옮기는 경우
	{
		if (s[i] == 'B')
			sw = 1;

		if (sw&&s[i] == 'R')
			cnt++;
	}

	sw = 0;
	if (cnt < m)
		m = cnt;
	cnt = 0;

	for (int i = 0; i < n; i++)		//B를 왼쪽으로 모두 옮기는 경우
	{
		if (s[i] == 'R')
			sw = 1;

		if (sw && s[i] == 'B')
			cnt++;
	}

	sw = 0;
	if (cnt < m)
		m = cnt;
	cnt = 0;

	for (int i = n - 1; i >= 0; i--)	//B를 오른쪽으로 모두 옮기는 경우
	{
		if (s[i] == 'R')
			sw = 1;

		if (sw&&s[i] == 'B')
			cnt++;
	}

	if (cnt < m)
		m = cnt;

	cout << m << endl;

	return 0;
}