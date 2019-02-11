#include <iostream>
using namespace std;
int f[10005];
int father(int x)
{
	return f[x]==x?x:f[x]=father(f[x]);
}
void link(int a,int b)
{
	f[father(a)]=father(b);
}
int check(int a,int b)
{
	return father(a)==father(b)?1:0;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		f[i]=i;
	for(int i=0;i<m;++i)
	{
		int t,ans1,ans2;
		cin>>t>>ans1>>ans2;
		if(t==1)
		{
			if(!check(ans1,ans2))
				link(ans1,ans2);
		}
		if(t==2)
		{
			if(check(ans1,ans2))
				cout<<'Y'<<endl;
			else
				cout<<'N'<<endl;
		}
	}
	return 0;
}
