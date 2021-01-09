#include <iostream>
#include <algorithm>
using namespace std;

int sum[100001];					//보석의 가치의 누적합(prefix sum)

int main()
{
	int n, m;						//n : 보석 수, m : 연속적으로 주울 수 있는 보석의 최소 개수->그 이상 가능!
	int x;							//보석의 가치
	int result = 0;					//가치의 총 합의 최댓값
	int temp = 0;					//sum 배열의 누적합 중 최솟값	

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> x;

		sum[i + 1] = sum[i] + x;	
	}

	for (int i = m - 1; i < n; i++) 
	{
		temp = min(sum[i - (m - 1)], temp);
		result = max(sum[i + 1] - temp, result);
	}

	cout << result << endl;

	return 0;
}

//일단 배열의 끝점 인덱스가 m - 1보다도 작다면 그 앞에서 절대 길이 m 이상인 부분 배열을 고를 수가 없으니까 
//결과는 아무것도 고르지 못하는 0이 됩니다.
//
//또, 인덱스가 m - 1 이상이어도 후보의 수가 한정됩니다.일단 자신보다 m - 1칸 앞까지의 sum 값들은 후보에 
//들어가지 않죠!이들을 고른다는 건 길이 m보다 작은 부분 배열을 고르겠다는 말이니까.
//
//따라서 sum을 저장해 두었다가 늦은 시기에 비로소 min 값을 갱신해주는 식으로 문제를 해결할 수 있습니다.
