#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n;												//입력할 단어의 개수, 1<=n<=10
	int alphabet[26] = { 0, };							//알파벳	-> 알파벳 갯수를 세기 위한 배열
	int num[10] = { 0, };								//자리 수의 개수를 집어 넣을 배열
	string *word;										//입력하는 단어
	int len = 0;										//입력한 문장 word의 길이
	int sum = 0;										//총 합
	int alphabet_num = 0;								//alphabet 배열에 들어있는 알파벳의 개수를 구하기 위한 변수
	int start_value = 9;								//알파벳 대문자를 0~9 숫자 중 하나로 바꿀 때, 
														//항상 9부터 시작하므로 이걸 가져다 사용!

	cin >> n;

	word = new string[n];

	for (int i = 0; i < n; i++)
	{
		cin >> word[i];									//word는 string이므로 꼭 #include <string>를 써줘야 한다.
	}

	for (int i = 0; i < n; i++)
	{
		len = word[i].length();

		for (int j = 0; j <len; j++)
		{
			alphabet[word[i].at(j) - 65] += (int)pow(10, len - j - 1);		//즉, 각 알파벳에 10^(len-j-1)을 더해준다. 
		}																	//-> 이러면 알파벳이 중복으로 쓰일 때의 문제를 막을 수 있다.

		for (int j = len - 1; j >= 0; j--)
		{
			num[j] += 1;										//각 자리수에 몇 개의 수가 필요한지 적는다.
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] != 0)									//alphabet 배열의 값 = 0 인 경우
			alphabet_num += 1;									//alphabet_num에 1을 더한다.
	}
		
	sort(alphabet, alphabet + alphabet_num);					//오름차순 정렬	-> 즉, alphbet 배열을 작은 순서대로 정리!!!

	for (int i = alphabet_num - 1; i >= 0; i--)
	{
		sum += alphabet[i] * start_value;						//sum에 값을 저장.
		start_value--;											//start_value는 9부터 시작해서 1씩 줄어들어야 한다.
	}

	cout << sum << endl;

	return 0;
}	//상



/*for (int i = 0; i < n; i++)
{
for (int j = 0; j < word[i].length(); j++)
cout << word[i].at(j) << endl;						//at()는 string에서 한 글자 씩 사용할 수 있도록 하는 것.*/