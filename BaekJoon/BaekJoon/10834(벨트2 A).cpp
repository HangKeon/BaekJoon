#include <iostream>
using namespace std;

int main()
{
	int n;							//벨트의 개수
	int a[1001], b[1002] = { 0, };	//a : 벨트의 형태(0 : 안꼬인 형태, 1 : 꼬인 형태)
									//b : 바퀴의 방향(0 : 시계방향, 1 : 반시계방향)
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		if (a[i] == 0)				//안꼬인 형태일때
		{
			if (b[i] == 0)			//시계방향이라면
				b[i + 1] = 0;
			else					//반시계방향이라면
				b[i + 1] = 1;
		}
		else if (a[i] == 1)			//꼬인 형태일때
		{
			if (b[i] == 0)			//시계방향이라면
				b[i + 1] = 1;
			else					//반시계방향이라면
				b[i + 1] = 0;
		}
	}

	for (int i = 0; i <= n; i++)
		cout << b[i] << ' ';
	cout << endl;

	return 0;
}