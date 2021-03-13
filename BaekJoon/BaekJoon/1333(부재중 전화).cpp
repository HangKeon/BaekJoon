#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, l, d;						//n : 노래 수, l : 모든 노래 길이, d : 전화벨 간격
	int bell = 0;						//전화벨이 들리는 시간
	vector<int> v;						//노래가 재생되는 과정(1 : 노래 재생 중, 0 :노래가 안 들림)

	cin >> n >> l >> d;

	while (n--)
	{
		for (int i = 0; i < l; i++)		//음악이 재생중인 경우
			v.push_back(1);

		for (int i = 0; i < 5; i++)		//음악이 멈춘 경우
			v.push_back(0);
	}

	while (1)
	{
		bell += d;

		if (v[bell] == 0)				//노래 사이 간격에서 벨이 울리는 경우
			break;

		if (bell > v.size())			//노래가 모두 끝난 후 벨이 울리는 경우
			break;
	}

	cout << bell << endl;

	return 0;
}