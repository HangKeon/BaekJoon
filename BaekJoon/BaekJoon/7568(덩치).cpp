#include <iostream>
using namespace std;

int main() 
{
	int n;						//사람 수
	int x[51];					//몸무게
	int y[51];					//키
	int d[51];					//덩치 등수

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	for (int i = 0; i < n; i++)	//등수는 1부터 시작하므로 모두 1로 바꿈.
		d[i] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (x[i] > x[j] && y[i] > y[j])			//i가 j보다 덩치가 큰 경우
				d[j]++;
			else if (x[i] < x[j] && y[i] < y[j])	//j가 i보다 덩치가 큰 경우
				d[i]++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << d[i] << ' ';
	cout << endl;


	return 0;
}