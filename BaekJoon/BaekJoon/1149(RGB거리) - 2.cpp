#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3];					//��� ���� ĥ�ϴ� �ּ� ���

int main()
{
	int n;							//���� ��
	int arr[1001][3];				//RGB�� ����� ����
	
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];

	//dp[0]�� arr[0]�� ���� -> ù��° ���� ����� ����
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < n; i++)	
	{
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];	//i��° ���� R�� ĥ�ϴ� �ּ� ���
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];	//i��° ���� G�� ĥ�ϴ� �ּ� ���
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];	//i��° ���� B�� ĥ�ϴ� �ּ� ���
	}

	cout << min({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] }) << endl;

	return 0;
}