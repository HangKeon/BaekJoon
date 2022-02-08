#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[100001];			//v[����] = ��ǥ 

int main()
{
	int n;						//������ ����
	int x, y;					//x : ��ǥ(10��),  y : ����
	int cnt = 0;				//y�� �ִ�
	int size;					//v[i].size()
	long long sum = 0;			//ȭ��ǥ�� �� ���� �ּڰ�(-21��~+21��)

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;

		v[y].push_back(x);

		cnt = max(cnt, y);
	}

	for (int i = 1; i <= cnt; i++)				//����
	{
		int size = v[i].size();

		sort(v[i].begin(), v[i].end());

		if (size < 2)							//�ƿ� ���ų� 1�� �ִ� ���
			continue;

		for (int j = 0; j < size; j++)			//��ǥ�� �ε���
		{
			if (j == 0)							//�Ǿ� 
				sum += v[i][j + 1] - v[i][j];
			else if (j == size - 1)				//�� ��
				sum += v[i][j] - v[i][j - 1];
			else
				sum += min(v[i][j + 1] - v[i][j], v[i][j] - v[i][j - 1]);
		}
	}

	cout << sum << endl;

	return 0;
}