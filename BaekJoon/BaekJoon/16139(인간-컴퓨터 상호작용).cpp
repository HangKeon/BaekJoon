#include <iostream>
#include <string>
using namespace std;

int arr[200001][27];		//arr[s의 인덱스][알파벳] : s의 인덱스까지의 알파벳의 누적 갯수

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(0);

	string s;							//입력할 문자열
	int q;								//질문할 횟수
	char c;								//찾을 문자
	int l, r;							//문자열s에서 문자c가 쓰인 범위

	cin >> s >> q;

	for (int i = 0; i < s.length(); i++)
	{
		if(i==0)
			arr[i][s[i] - 'a'] = 1;
		else
		{
			for (int j = 0; j < 26; j++)
				arr[i][j] = arr[i - 1][j];

			arr[i][s[i] - 'a']++;
		}
	}

	for (int i = 0; i < q; i++)
	{
		int cnt = 0;					//문자c의 갯수

		cin >> c >> l >> r;

		if (l == 0)
			cout << arr[r][c - 'a'] << "\n";
		else
			cout << arr[r][c - 'a'] - arr[l - 1][c - 'a'] << "\n";
	}

	return 0;
}