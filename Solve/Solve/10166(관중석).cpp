#include <iostream>
using namespace std;

int arr[2001][2001];			//arr[����][�и�] : 0�̸� �� ���� ������� x ���, 1 : �̹� ����� ���

int GCD(int a, int b)			//�ִ����� ���ϴ� �Լ�
{
	int c;

	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main()
{
	int a, b;					//���� ������
	int gcd;					//�ִ�����
	int temp;					//arr���� ������ ����
	int cnt = 0;				//���߼� ����

	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			gcd = GCD(i, j);

			temp = arr[j / gcd][i / gcd];

			if (temp == 0)
			{
				arr[j / gcd][i / gcd] = 1;
				cnt++;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}