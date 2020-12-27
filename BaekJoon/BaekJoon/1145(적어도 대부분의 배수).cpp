#include <iostream>
using namespace std;

#include <algorithm>

int arr[5];
int main()
{
	int cnt = 0;
	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	/*cout<<"<sort전>"<<endl;
	for(int i=0;i<5;i++)
	cout<<arr[i]<<" "<<endl;
	*/

	sort(arr, arr + 5);

	/*cout << "<sort후>" << endl;
	for (int i = 0; i<5; i++)
		cout << "arr[" << i << "] = " << arr[i] << " ";
	cout << endl;
	*/

	for (int i = arr[0]; ; i++)
	{
		cnt = 0;
		//cout << "i의 값(1)(" << i << ") = " << i << "	cnt = " << cnt << endl;

		for (int j = 0; j < 5; j++)
		{
			//cout << "i의 값(2)(" << i << ", " << j << ") = " << i << "	cnt = " << cnt << endl;
			if (i % arr[j] == 0)
			{
				cnt++;
				//cout<<"i의 값(3)("<<i<<") = "<<i<<endl;
			}
		}

		if (cnt >= 3)
		{
			cout << i;
			return 0;
		}
	}
}

//중상