#include <iostream>
using namespace std;
int a[10005];
int main()
{
	int n,m,num=0,num1=0;
	cin>>n>>m;
	for(int i=1;i<=n;i=++i%n)
	{
		if(num1==n)
			break;
		if(!i)
			i=n;
		if(!a[i])
			num++;
		if(num==m)
		{
			cout<<i<<' ';
			a[i]=1;
			num=0;
			num1++;
		}
	}
	return 0;
}
