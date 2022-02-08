#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;					//n : ������ ��, m : �� ����
	int sum = 0;				//������ ������� ��
	int ans;					//������ ����� �� �ִ�
	int s = 0;					//���� ���� ����
	int e = 0;					//���� ū ����
	int mid;					//������ �� �ִ� ����
	int arr[10001];				//���濡�� �䱸�� ����

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		e = max(arr[i], e);
	}

	cin >> m;

	while (s <= e)
	{
		mid = (s + e) / 2;
		sum = 0;

		for (int i = 0; i < n; i++)
			sum += min(arr[i], mid);

		if (sum <= m)							//����� �� �ִ� ���
		{
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	cout << ans;

	return 0;
}