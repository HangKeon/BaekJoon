#include <iostream>
#include <string>
using namespace std;

int main()
{
	string color[] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
	string t;								//입력할 문자열
	int mem[3];								//입력한 문자열에 맞는 숫자를 저장할 배열
	long long resist = 0;					//저항값

	for (int i = 0; i < 3; i++)
	{
		cin >> t;

		for (int j = 0; j < 10; j++)
		{
			if (color[j] == t)				//만약 color과 입력하는 문자열 t가 같은 경우
				mem[i] = j;					//mem에 j값을 저장 -> 이때 j는 color에 저장된 문자열들의 인덱스 값
		}
	}

	resist = mem[0] * 10 + mem[1];			//처음 색 2개를 더함

	for (int i = 0; i < mem[2]; i++)			//마지막 색을 곱함
		resist *= 10;

	cout << resist << endl;


	return 0;
}