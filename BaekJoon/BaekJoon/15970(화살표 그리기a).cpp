#include <iostream>
using namespace std;

int main()
{
	int n;							//점들의 개수
	int x = 0, y = 0;				//x, y : color가 1,2를 저장할 배열의 인덱스
	int pos[5001];					//점의 좌표를 저장할 배열
	int color[5001];				//색을 저장할 배열
	int first[5001], second[5001];	//첫 번째 줄, 두 번째 줄에 관한 배열

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> pos[i] >> color[i];

		if (color[i] == 1)			//만약 색깔이 1이라면
			first[x++] = pos[i];	//first에 pos를 저장
		else						//만약 색깔이 2라면
			second[y++] = pos[i];	//second에 pos를 저장
	}

	for (int i = 0; i < x; i++)		//첫 번째 줄 출력
		cout << first[i] << ' ';
	cout << endl;

	for (int i = 0; i < y; i++)		//두 번째 줄 출력
		cout << second[i] << ' ';
	cout << endl;


	 



	return 0;
}