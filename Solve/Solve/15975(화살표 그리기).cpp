#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[100001];			//v[»ö±ò] = ÁÂÇ¥ 

int main()
{
	int n;						//Á¡µéÀÇ °¹¼ö
	int x, y;					//x : ÁÂÇ¥(10¾ï),  y : »ö±ò
	int cnt = 0;				//yÀÇ ÃÖ´ñ°ª
	int size;					//v[i].size()
	long long sum = 0;			//È­»ìÇ¥ÀÇ ÃÑ ÇÕÀÇ ÃÖ¼Ú°ª(-21¾ï~+21¾ï)

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;

		v[y].push_back(x);

		cnt = max(cnt, y);
	}

	for (int i = 1; i <= cnt; i++)				//»ö±ò
	{
		int size = v[i].size();

		sort(v[i].begin(), v[i].end());

		if (size < 2)							//¾Æ¿¹ ¾ø°Å³ª 1°³ ÀÖ´Â °æ¿ì
			continue;

		for (int j = 0; j < size; j++)			//ÁÂÇ¥ÀÇ ÀÎµ¦½º
		{
			if (j == 0)							//¸Ç¾Õ 
				sum += v[i][j + 1] - v[i][j];
			else if (j == size - 1)				//¸Ç µÚ
				sum += v[i][j] - v[i][j - 1];
			else
				sum += min(v[i][j + 1] - v[i][j], v[i][j] - v[i][j - 1]);
		}
	}

	cout << sum << endl;

	return 0;
}