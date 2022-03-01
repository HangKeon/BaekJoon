#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//���� �ڵ�

int arr[51][51];						//���� ģ�� :1, �����ؼ� ģ�� : 2, ģ��x : 0 

int main()
{
	int n;								//��� �� 
	int cnt = 0;						//���� ������ ����� 2-ģ�� ��
	int temp;							//�� ������� 2-ģ�� ��
	string s[51];						//Y : ģ��o, N : ģ��x

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)					//�ڱ� �ڽ��� ģ���� �� �� ���ٰ� ������ ����.
				continue;

			if (s[i][j] == 'Y')			//i,j�� ģ���� ���
				arr[i][j] = 1;
			else						//i,j�� ģ���� �ƴ� ���
				arr[i][j] = 1e9;
		}
		

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == j || j == k || k == i)		//�ڱ� �ڽ��� ���캼 �ʿ䰡 ����.
					continue;
				 
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}

	for (int i = 1; i <= n; i++)
	{
		temp = 0;

		for (int j = 1; j <= n; j++)
		{
			if (i == j)					//�ڱ� �ڽ��� ģ���� �� �� ����.
				continue;
			else if (arr[i][j] <= 2)	//ģ���� ���(1,2)
				temp++;
		}

		cnt = max(cnt, temp);
	}

	cout << cnt << endl;

	return 0;
}