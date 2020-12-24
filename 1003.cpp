// 归并排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//来自大佬的程序

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int L, int mid, int R)
{
	int* help = new int[R - L + 1];
	int p1 = L, p2 = mid + 1, i = 0;
	while (p1 <= mid && p2 <= R)
	{
		help[i++] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1++];
	}
	while (p1 <= mid)
		help[i++] = arr[p1++];
	while (p2 <= R)
		help[i++] = arr[p2++];

	for (i = 0; i < R - L + 1; i++)
	{
		arr[L + i] = help[i];
	}
}
void sortprocess(vector<int>& arr, int L, int R)
{
	if (L < R)
	{
		int mid = L + ((R - L) >> 2);  //  (L+R)/2
		sortprocess(arr, L, mid);
		sortprocess(arr, mid + 1, R);
		merge(arr, L, mid, R);
	}
}

void MergeSort(vector<int>& arr, int L, int R)
{
	if (arr.size() < 2)
		return;
	sortprocess(arr, L, R);
}


int main()
{
	vector<int> arr;
	int n, temp,i=0;
	cin >> n;  //输入n个数
	for (i = 0; i < n; i++)
	{
		cin >> temp;  //输入数据
		arr.push_back(temp);
	}

	MergeSort(arr, 0, arr.size() - 1);

	for (i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;


	return 0;

}
/*我的垃圾程序
#include<malloc.h>
#include <iostream>
using namespace std;
void write_data(long* a)
{
	int i = 0;
	char c;
	cin >> a[i++];
	while ((c = getchar()) != '\n')
	{
		cin >> a[i++];
	}
}

void merge(long*a,int left,int mid,int right)
{

	int* temp;
	temp = (int*)malloc((right-left+1)*sizeof(int));
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j]) temp[k] = a[i], i++, k++;
		else temp[k] = a[j], j++, k++;
	}
	while(i<=mid)
	{
		temp[k] = a[i], i++, k++;
	}
	while (j <= right) 
	{
		temp[k] = a[j], j++, k++;
	}

	for (k = 0, i = left; i <= right; k++, i++)
		a[i] = temp[k];

	free(temp);
}
void merge_pass(long*a,int lenth,int n)
{
	int i;
	for ( i = 0; i + 2 * lenth - 1 < n; i =i+ 2 * lenth)
		merge(a, i, i + lenth - 1, i + 2 * lenth - 1);
	if (i + lenth - 1 < n)
		merge(a, i, i + lenth - 1, n - 1);
}
void merge_sort(long*a,int n)
{
	for (int lenth = 1; lenth < n; lenth *= 2)
		merge_pass(a,lenth,n);
}
int main()
{	
	int n;
	cin >> n;
	long* a;
	a = new long[n];
	write_data(a);
	merge_sort(a,n);
		for (int i = 0; i < n; i++)
		{
			cout << a[i]<<endl;
		}
		delete a;
}
*/
