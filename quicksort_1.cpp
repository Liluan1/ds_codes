#include<iostream>
#include<stdlib.h> 
using namespace std;
int a[10] = {2,3,213,132,14,4,45,356,4,7};
int partition(int lo,int hi)
{
	swap(a[lo],a[lo+rand()%(hi-lo+1)]);
	int pivot = a[lo];
	while(lo<hi)
	{
		while(lo<hi&&pivot<=a[hi])
			hi--;
		if(lo<hi)
			a[lo++] = a[hi];
		while(lo<hi&&a[lo]<=pivot)
			lo++;
		if(lo<hi)
			a[hi--] = a[lo];
	}
	a[lo] = pivot;
	return lo;
} 
void quicksort(int lo,int hi)
{
	if(hi-lo<2)
		return ;
	int mi = partition(lo,hi-1);
	quicksort(lo,mi);
	quicksort(mi+1,hi);
}
int main(void)
{
	quicksort(0,10);
	for(int i=0;i<10;++i)
		cout<<a[i]<<" ";
}
