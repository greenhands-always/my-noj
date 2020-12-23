#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void quicksort(vector<int> &a, int s, int e)
{
	// s 是数组的开始，e是数组的最后一个元素，k要求的前k个最大值
	int m = a[s];
	if (s >= e)
		return;
	int i = s, j = e;
	while (i != j)
	{
		while (j > i && a[j] >= m)
		{
			j--;
		}
		swap(a[i], a[j]);
		while (j > i && a[i] <= m)
		{
			i++;
		}
		swap(a[i], a[j]);
	}
	quicksort(a, s, i - 1);
	quicksort(a, i + 1, e);

}

int main()
{
	int n,i=0,temp;
	vector<int> a;
	cin >> n;
	
	char c;
	for (i = 0; i < n; i++)
	{
		cin >> temp;
		a.push_back(temp);
	}
	
	quicksort(a, 0, n - 1);
	for (i = 0; i < n; i++)
		cout << a[i] << endl;
	return 0;
}