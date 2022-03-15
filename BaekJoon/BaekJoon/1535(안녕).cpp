#include <iostream>
#include<algorithm>
using namespace std;

int dp[21][101];					//dp[��� ��ȣ][���� ü��]= ���� ���� ��� �ִ� ����

int main()
{
	int n;							//��� ��
	int ans = 0;					//�ִ� ��� ����
	int L[21];						//�Ҹ�Ǵ� ü��
	int J[21];						//��� ���

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> L[i];
	
	for (int i = 1; i <= n; i++)
		cin >> J[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (j + L[i] < 100)												//�λ� ������ ���
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + L[i]] + J[i]);	//���� ��� = max(�λ� �� ���� ���� ��� ����, �λ� ���� ���� ��� ���� + �߰� ��� ����)
			else															//�λ簡 �Ұ����� ���
				dp[i][j] = max(dp[i - 1][j], dp[i][j]);						//���� ��� = max(���� ���, ���� ���)	

			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << endl;

	return 0;
}