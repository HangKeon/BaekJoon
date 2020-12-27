#include <iostream>
using namespace std;

char num_str[10][7] = {				//숫자 표현하는 배열
{ '-','|',' ','|','|','-','|' },	//0
{ ' ',' ',' ','|',' ',' ','|' },	//1
{ '-',' ','-','|','|','-',' ' },	//2
{ '-',' ','-','|',' ','-','|' },	//3
{ ' ','|','-','|',' ',' ','|' },	//4
{ '-','|','-',' ',' ','-','|' },	//5
{ '-','|','-',' ','|','-','|' },	//6
{ '-',' ',' ','|',' ',' ','|' },	//7
{ '-','|','-','|','|','-','|' },	//8
{ '-','|','-','|',' ','-','|' }		//9
};

int str_to_int(char ch)				//입력된 문자열n을 하나씩 쪼개 숫자로 바꾸기 위한 함수
{
	switch (ch)
	{
	case '0':return 0;
	case '1':return 1;
	case '2':return 2;
	case '3':return 3;
	case '4':return 4;
	case '5':return 5;
	case '6':return 6;
	case '7':return 7;
	case '8':return 8;
	case '9':return 9;
	default:
		return -1;
	}
}

void repeat(char ch, int n)							//repeat(반복할 문자, 반복 횟수)
{
	while (n--)
		cout << ch;
}

void print(int s, const char* str, int num)			//print(main 함수의 s, main 함수의 n, n의 크기)
{
	for (int i = 0; i < 2 * s + 3; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (i == 0)
			{
				cout << ' ';
				repeat(num_str[str_to_int(str[j])][0], s);
				cout << ' ';
			}
			else if (i < s + 1)
			{
				cout << num_str[str_to_int(str[j])][1];
				repeat(' ', s);
				cout << num_str[str_to_int(str[j])][3];
			}
			else if (i == s + 1)
			{
				cout << ' ';
				repeat(num_str[str_to_int(str[j])][2], s);
				cout << ' ';
			}
			else if (i < 2 * s + 2)
			{
				cout << num_str[str_to_int(str[j])][4];
				repeat(' ', s);
				cout << num_str[str_to_int(str[j])][6];
			}
			else
			{
				cout << ' ';
				repeat(num_str[str_to_int(str[j])][5], s);
				cout << ' ';
			}
			cout << ' ';											//조건에 각 숫자는 한 칸씩 띄우라고 함.
		}
		cout << endl;												//조건에서 입력된 줄마다 다른 줄에 입력해야 함.
	}
}



int main()
{
	int s;								//s = 숫자를 표시하는 크기
	char n[8];							//n = 출력될 숫자

	while (1)
	{
		cin >> s >> n;

		if (s == 0 && n == 0)			//탈출조건
			return 0;

		print(s, n, strlen(n));

	}

	return 0;
}