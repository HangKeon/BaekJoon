#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, k;						//n : 사람 수, k : 거리
	int cnt = 0;					//햄버거를 먹을 수 있는 사람 수
	string s;						//문자열

	cin >> n >> k;

	cin >> s;

	for (int i = 0; i < n; i++)
	{
		for (int j = i - k; j <= i + k; j++)			//P를 기준으로 H를 찾을 때의 범위
		{
			if (j < 0 || j == i || j >=n)				//인덱스 범위를 벗어나거나 i와 같은 경우는 제외!
				continue;

			if (s[i] == 'P')
			{
				if (s[j] == 'H')
				{
					cnt++;
					s[i] = 'k';
					s[j] = 'k';
					break;
				}
			}
		}
	}

	cout << cnt << endl;


	return 0;
}