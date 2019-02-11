#include<iostream>
using namespace std;
int a[10] = {4,2,7,13,22,3,17,9,11,5};
Quicksort(int lo,int hi)
{
	if(lo < hi)
	{
		int i = lo,j = hi;
		while(i < j)
		{
			while(a[i] <= a[j] && i < j)
				j--;
			swap(a[i],a[j]);
			while(a[i] <= a[j] && i < j)
				i++;
			swap(a[i],a[j]);
		}
		Quicksort(lo,i);
		Quicksort(i+1,hi);
	}
}

int main(void)
{
	Quicksort(0,9);
	for(int i=0;i<10;++i)
		cout<<a[i]<<" ";
	return 0;
}
