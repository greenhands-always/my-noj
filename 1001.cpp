#include<iostream>
using namespace std;
int Binsearch(int *a, int k, int n)
{
	int left=0, right=n-1, mid;
	while(left <= right)
	{		
			mid = (left + right) / 2;	
			if (a[mid] == k)
				return 1;
			if (a[mid] > k)
				{
				right = mid - 1;

				}
			else
				{
				left = mid + 1;
				}	
					
	}
	return 0;
}
int main()
{
	int n = 0, i = 0, findamount = 0;
	cin >> n;
	int* a = new int[n], *value = new int [findamount];
	for (i = 0; i < n; i++)
		cin >> a[i];
	cin >> findamount;
	for (i = 0; i < findamount; i++)
		cin >> value[i];
	for (i = 0; i < findamount; i++)
	{
		if (Binsearch(a, value[i], n)) cout << "Yes\n";
		else cout << "No\n";
	}
	delete [] value, a;
	
	return 0;
}

