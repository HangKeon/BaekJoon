#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;							//가입한 사람 수

	cin >> n;

	vector<int> v(n);					//나이
	vector<string> s(n);				//이름

	for (int i = 0; i < n; i++)			//입력
	{
		cin >> v[i] >> s[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)	//나이순 정렬 -> 입력된 순서대로 정렬됨(나이가 같은경우)
		{
			if (v[j] > v[j + 1])
			{
				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;

				string tmp2 = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp2;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << v[i] << " " << s[i] << endl;


	return 0;
}