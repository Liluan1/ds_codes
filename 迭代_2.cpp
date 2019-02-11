# include <iostream>
# include <algorithm>
using namespace std;

void max(int A[],int lo,int hi,int &x1,int &x2)
{
	if(A[x1=lo]<A[x2=lo+1])
		swap(x1,x2);
	for(int i=lo+2;i<hi;++i)
		if(A[x2]<A[i])
			if(A[x1]<A[x2=i])
				swap(x1,x2);
}
 
int main(void)
{
	int a[] = {1,2,3,4,5,6,7,8,9,0};
	int max1,max2;
	max(a,0,10,max1,max2);
	cout<<a[max1]<<" "<<a[max2]<<endl;
	return 0;
}
//最好情况 1+(n-2)*1 = n-1
//最坏情况 1+(n-2)*2 = 2n-3 
