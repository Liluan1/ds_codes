# include <iostream>
using namespace std;

void max(int A[],int lo,int hi,int &x1,int &x2)
{
	if(lo+2==hi)
	{
		if(A[x2=lo]>A[x1=lo+1])
			swap(x1,x2);
		return ;
	}
	if(lo+3==hi)
	{
		if(A[x2=lo]>A[x1=lo+1])
			swap(x1,x2);
		if(A[lo+2]>A[x2])
			if(A[x2=lo+2]>A[x1])
				swap(x1,x2);
		return ;
	}
	int mi = (lo+hi)/2;
	int x1L,x2L;
	max(A,lo,mi,x1L,x2L);
	int x1R,x2R;
	max(A,mi,hi,x1R,x2R);
	if(A[x1L]>A[x1R])
	{
		x1 = x1L;
		x2 = (A[x2L]>A[x1R])?x2L:x1R;
	}
	else
	{
		x1 = x1R;
		x2 = (A[x1L]>A[x2R])?x1L:x2R;
	}
}//T(n) = 2*T(n/2)+2 = 5n/3-2
int main(void)
{
	int a[10] = {1,2,3,4,5,6,7,8,9,0};
	int b,c;
	max(a,0,9,b,c);
	cout<<a[b]<<" "<<a[c];
	return 0;
}
