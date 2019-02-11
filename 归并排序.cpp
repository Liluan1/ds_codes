# include <cstdio>
int a[10] = {5,3,7,2,8,0,3,6,8,4};
void merge(int lo,int mid,int hi)
{
	int *A = a+lo;
	int lb = mid-lo;
	int *B = new int[lb];	//前区间 
	for(int i=0;i<lb;B[i]=A[i++]);
	int lc = hi-mid;
	int *C = a+mid;		//后区间 
	int i=0,j=0,k=0;
	while((j<lb)&&(k<lc))
	{
		while((j<lb)&&B[j]<=C[k])
			A[i++] = B[j++];
		while((k<lc)&&C[k]<=B[j])
			A[i++] = C[k++];
	}
	while(j<lb)
		A[i++] = B[j++];
	delete [] B;
} 

void  mergeSort(int lo, int hi)
{
	if(hi-lo<2)
		return;
	int mid = (lo+hi)>>1;
	mergeSort(lo,mid);
	mergeSort(mid,hi);
	merge(lo,mid,hi);
}

int main(void)
{
	mergeSort(0,10);
	for(int i=0;i<10;++i)
		printf("%d",a[i]);
	return 0;
}
