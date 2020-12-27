#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;							//식재료의 개수
int mp, mf, ms, mv;				//단백질, 지방, 탄수화물, 비타민
int arr[16][5];
int sum;						//조건을 충족하는 것의 가격
int ans = 2e9;					//가격이 가장 작은 값
vector<int> vec;				//만족하는 값들의 번호를 저장
vector<int> vec2;

void dfs(int p, int f, int s, int v, int price, int idx)		//dfs(단백질, 지방, 탄수화물, 비타민, 가격, 번호)
{
	if (ans < price)											//가격으로 미리 거름
		return;

 	if (p >= mp && f >= mf && s >= ms && v >= mv)
	{
		if (ans > price)
		{
			ans = price;
			vec2 = vec;
		}

		return;
	}

	for (int i = idx; i <= n; i++)
	{
		vec.push_back(i);

		dfs(p + arr[i][0], f + arr[i][1], s + arr[i][2], v + arr[i][3], price + arr[i][4], i+1);

		vec.pop_back();
	}
}

int main()
{
	cin >> n >> mp >> mf >> ms >> mv;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];

	
	dfs(0,0,0,0,0,1);
	
	if (ans == 2e9)							//조건을 만족하는 답이 없는 경우
	{
		cout << "-1" << endl;
		return 0;
	}


	cout << ans << endl;

	for (int i = 0; i < vec2.size(); i++)
		cout << vec2[i] << ' ';

	cout << endl;


	return 0;
}