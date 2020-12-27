#include <iostream>
using namespace std;

int main()
{
	int n, m;							//n = Çï¸äÀÇ °³¼ö, m = Á¶³¢ÀÇ °³¼ö
	int h[1001], a[1001];				//h = Çï¸äÀÇ ¹æ¾î·Â, m = Á¶³¢ÀÇ ¹æ¾î·Â
	int sum = 0, max_h = 0, max_a = 0;	//sum = ÇÕ, max_h = Çï¸ä ¹æ¾î·Â ÃÖ´ë°ª, max_a = Á¶³¢ ¹æ¾î·Â ÃÖ´ë°ª

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> h[i];

		if (h[i] > max_h)
			max_h = h[i];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a[i];

		if (a[i] > max_a)
			max_a = a[i];
	}

	sum = max_h + max_a;

	cout << sum << endl;

	return 0;
}