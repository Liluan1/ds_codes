# include <iostream>
using namespace std;
//�����δ�ֵ��Ҫ��Ƚϴ��������ܵ�С 
void max2(int A[], int lo, int hi, int& x1, int& x2)
{
	x1=lo;
	x2=lo;
	for(int i=lo+1;i<hi;++i)
		if(A[x1]<A[i])
			x1 = i;
	for(int i=lo+1;i<x1;++i)
		if(A[x2]<A[i])
			x2 = i;
	for(int i=x1+1;i<hi;++i)
		if(A[x2]<A[i])
			x2 = i;
}

int main(void)
{
	int a[10] = {1,2,3,4,5,6,7,8,9,0};
	int max,max1;
	max2(a,0,10,max,max1);
	cout<<a[max]<<" "<<a[max1]<<endl;
	return 0;
}
//�������������˵����������������һ���ģ�����2n-3 
