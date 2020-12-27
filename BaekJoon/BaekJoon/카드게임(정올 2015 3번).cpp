#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, sum = 0;										//카드 수, 총 합
	vector<int> left;									//왼쪽 카드
	vector<int> right;									//오른쪽 카드
	int j = 0, k = 0;

	cin >> n;

	for (int i = 0; i < n; i++)							//왼쪽 카드를 입력
	{
		int lef;
		cin >> lef;

		left.push_back(lef);
	}

	for (int i = 0; i < n; i++)							//오른쪽 카드를 입력
	{
		int rig;
		cin >> rig;

		right.push_back(rig);
	}

	while (1)
	{
		if (left[j] > right[k])							//왼쪽 카드 값 > 오른쪽 카드 값
		{
			sum += right[k];
			k++;
		}
		else if (left[j] < right[k])					//왼쪽 카드 값 < 오른쪽 카드 값
		{
			j++;
		}
		else											//왼쪽 카드 값 = 오른쪽 카드 값
		{												//더 이상 진행할 수 없기 떄문에 (1)조건을 사용해 오른쪽, 왼쪽 둘 다 버린다.
			k++;
			//j++;
		}

		if (j == n || k == n)							//탈출 조건
			break;
	}

	cout << sum << endl;

	return 0;
}