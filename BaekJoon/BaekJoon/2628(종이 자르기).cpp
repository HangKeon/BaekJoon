#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//2001 초등부 1번

int main()
{
	int a, b;					//a : 가로, b : 세로
	int n;						//칼로 잘라야 하는 점선의 개수
	int x, y;					//x : 가로(0), 세로(1), y = 점선 번호
	int max = 0;				//넓이의 최댓값을 저장할 변수
	vector<int> zero;			//가로로 자르는 점선 -> 높이의 번호를 저장
	vector<int> one;			//세로로 자르는 점선 -> 너비의 번호를 저장

	cin >> a >> b;

	zero.push_back(b);			//높이를 추가 -> 높이의 점선 번호
	one.push_back(a);			//너비를 추가 -> 너비의 점선 번호

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;

		if (x == 0)				//가로로 자르는 경우
			zero.push_back(y);	//높이의 번호를 저장
		else					//세로로 자르는 경우
			one.push_back(y);	//너비의 번호를 저장
	}

	//오름차순으로 정렬
	sort(zero.begin(), zero.end());
	sort(one.begin(), one.end());

	for (int i = one.size()-1; i > 0; i--)
	{
		one[i] = one[i] - one[i - 1];
	}

	for (int i = zero.size()-1; i >0 ; i--)
	{
		zero[i] = zero[i] - zero[i - 1];
	}

	//오름차순으로 정렬
	sort(zero.begin(), zero.end());
	sort(one.begin(), one.end());


	for (int i = 0; i < one.size(); i++)
	{
		for (int j = 0; j < zero.size(); j++)
		{
			if (max < one[i] * zero[j])
				max = one[i] * zero[j];
		}
	}

	cout << max;


	return 0;
}