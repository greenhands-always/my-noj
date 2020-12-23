#include<iostream>
using namespace std;
void write_data(int *a)
{
	int i = 0;
	char c;
	cin >> a[i++];
	while ((c = getchar()) != '\n')
	{
		cin >> a[i++];
	}
}
void write_value(int* value,int amount)
{
	int i = 0;
	char c;
	for(;i<amount;i++)
	cin >> value[i];
	
}
int Binsearch(int a[], int k,int n)
{
	int left=0,right=n-1,mid;
	while(left<=right)
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

// 1001二分查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
int main()
{
	int n = 0, i = 0, findamount = 0;
	cin >> n;
	int* a;
	a = new int[n];
	write_data(a);
	cin >> findamount;
	
	int *value;
	value = new int[findamount];
	write_value(value,findamount);
	for (i = 0; i < findamount; i++)
	{
		if (Binsearch(a, value[i], n)) cout << "Yes\n";
		else cout << "No\n";
	}
	delete value,a;
	
	return 0;
}

