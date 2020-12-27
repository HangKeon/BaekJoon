#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int l, c;					//l : 문장을 이루는 알파벳 개수, c : 알파벳 종류
char arr[16];				//저장할 알파벳 배열

void dfs(int idx, string s, int odd, int even)					//dfs(인덱스, 문자열, 모음 개수, 자음 개수)
{
	if (s.size() == l)											//출력 & 탈출조건
	{
		if (odd >= 1 && even >= 2)
		{
			cout << s << endl;
		}
		return;
	}

	for (int i = idx; i < c; i++)
	{
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')	//모음인 경우
			dfs(i + 1, s + arr[i], odd + 1, even);
		else																					//자음인 경우
			dfs(i + 1, s + arr[i], odd, even + 1);
	}
}

int main()
{
	cin >> l >> c;

	for (int i = 0; i < c; i++)
		cin >> arr[i];

	sort(arr, arr + c);

	dfs(0, "", 0, 0);

	return 0;
}