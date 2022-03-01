#include <iostream>
#include <algorithm>
using namespace std;

int dp[16];							//�� ��¥ �� �ִ� �ݾ�

int main()
{
	int n;							//��� �� ���� ��
	int ans = 0;					//���� �� �ִ� �ִ� ����
	int day;						//���� ��¥
	int time[16];					//��� �Ⱓ
	int price[16];					//����

	cin >> n;

	day = n;						//���� ��¥(n)�� ����

	for (int i = 1; i <= n; i++)
		cin >> time[i] >> price[i];
	
	for (int i = 1; i <= n; i++)
	{
		if (time[i] > day)			//�ɸ��� �Ⱓ > ���� ��¥ => Ż������
		{
			day--;					//���� ��¥�� 1 ����
			continue;
		}

		dp[i] = price[i];			//�ڱ� �ڽ��� ������ ����

		for (int j = 1; j < i; j++)
		{
			if (i - j >= time[j])	//(���� ��¥ - ���� ��¥) >= �ɸ��� �Ⱓ
			{
				dp[i] = max(dp[i], dp[j] + price[i]);	//������ �Ⱓ ���� �ִ� �ݾ�
			}
		}

		ans = max(dp[i], ans);		//�ִ� �ݾ� ã��
		
		day--;						//���� ��¥�� 1 ����
	}

	cout << ans << endl;

	return 0;
}