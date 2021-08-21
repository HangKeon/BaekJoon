#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;						//테스트케이스 갯수
	int n;					//수첩1/수첩2에 적어둔 정수의 갯수

	cin >> t;

	while (t--)
	{
		vector<int> v1, v2;		//수첩1,2에 적어둔 정수! -> n,m이 백만까지 가능하므로 벡터로 선언!(매번 초기화 필요하므로)
		int tmp;				//v1,v2의 값을 임시로 입력할 변수

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;

			v1.push_back(tmp);
		}

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;

			v2.push_back(tmp);
		}

		sort(v1.begin(), v1.end());		//이분탐색을 위해 v1을 오름차순 정렬!

		for (int i = 0; i < n; i++)
		{
			int flag = 0;				//0 : 수첩1에 없는 경우, 1 : 수첩1에 있는 경우
			int low = 0;				//v2의 가장 왼쪽에 있는 인덱스
			int high = n - 1;			//v2의 가장 오른쪽에 있는 인덱스
			int mid;					//v2와 비교할 v1의 인덱스

			while (low <= high)
			{
				mid = (low + high) / 2;


				if (v2[i] == v1[mid])		//v2에 v1과 같은 값이 있다면
				{
					flag = 1;
					break;
				}
				else if (v2[i] > v1[mid])	//v2의 값이 현재 v1보다 크다면
					low = mid + 1;
				else						//v2의 값보다 현재 v1이 크다면
					high = mid - 1;
			}

			cout << flag << "\n";
		}
	}

	return 0;
}