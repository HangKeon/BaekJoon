#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, s;					//n : ������ ����, s : ��
	int ans = 2e9;				//s�̻��� �� �߿��� ���� ª�� ����
	int cnt = 0;				//s�̻��� ���� ����
	int sum = 0;				//�κ���
	int l, r;					//l : ���� �ε���, r : �� �ε���
	int arr[100001];			//����

	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	l = 0, r = 0;

	while (r <= n)
	{
		if (sum < s)
		{
			sum += arr[r++];
			cnt++;
		}
		else						//sum >= s
		{
			ans = min(ans, cnt);
			sum -= arr[l++];
			cnt--;
		}
	}

	if (ans == 2e9)					//���� ����� ���� �Ұ����� ���
		cout << 0;
	else
		cout << ans;


	return 0;
}