#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[51][51];				//arr[i][j] : i -> j���� �����ϴ� Ƚ��

int main()
{
	int n;						//ȸ�� ��
	int a = 0, b = 0;			//ȸ����ȣ
	int cnt = 0;				//ȸ�� �ĺ� ��
	int ans = 100;				//ȸ�� �ĺ� ����
	int temp;					//�л����� ���� ū ������ ����
	vector<int> v;				//ȸ�� �ĺ��� ����

	cin >> n;

	for (int i = 1; i <= n; i++)		//ū ������ �ʱ�ȭ
		for (int j = 1; j <= n; j++)
			if (i != j)
				arr[i][j] = 100;

	while (1)
	{
		cin >> a >> b;

		if (a + b == -2)		//Ż������
			break;

		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);	//������ Ƚ����ŭ �����ش�.


	for (int i = 1; i <= n; i++)
	{
		temp = 0;							//ó���� ������ �ٲ� �� �ֵ��� 0���� �ʱ�ȭ

		for (int j = 1; j <= n; j++)
		{
			temp = max(temp, arr[i][j]);	//�л��� ���� ū ������ ã��
		}

		if (temp <= ans)					//�� ���� ���� �����ϸ�
		{
			if (ans != temp)				//������ �ٸ� ��� ȸ�� �ĺ��� �ٽ� ����
				v.clear();

			ans = temp;						//�װ� ȸ�� �ĺ� ������ ��ü

			v.push_back(i);					//ȸ�� �ĺ� ����
		}
	}

	sort(v.begin(), v.end());

	cout << ans << ' ' << v.size() << endl;

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	return 0;
}