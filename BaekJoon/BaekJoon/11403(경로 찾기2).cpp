#include <iostream>
#include <algorithm>
using namespace std;
//�÷��̵� �ͼ�

int main()
{
	int n;							//������ ����
	int arr[101][101];				//�׷���(0 : ����x, 1 : ����o)

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << ' ';

		cout << endl;
	}

	return 0;
}