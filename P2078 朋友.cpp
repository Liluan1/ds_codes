#include <iostream>
using namespace std;
int f[20005];
int father(int x)
{
	return f[x]==x?x:father(f[x]);
}
int check(int a,int b)
{
	return father(a)==father(b)?1:0;
}
void link(int a,int b)
{
	if(!check(a,b))
		f[father(a)]=father(b);
}
int main()
{
	int n,m,p,q;
	cin>>n>>m>>p>>q;
	for(int i=10000-m;i<=10000+n;++i)
		f[i]=i;
	for(int i=0;i<p+q;++i)
	{
		int a,b;
		cin>>a>>b;
		link(10000+a,10000+b);
	}
	int val1=0,val2=0;
	for(int i=10001;i<=10000+n;++i)
		if(check(10001,i))
			val1++;
	for(int i=9999;i>=10000-m;--i)
		if(check(9999,i))
			val2++;
	cout<<min(val1,val2);
	return 0;
}
