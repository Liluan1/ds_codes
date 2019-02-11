#include <iostream>
using namespace std;
int f[5005];
int father(int x)
{
	return f[x]==x?x:f[x]=father(f[x]);
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
	int n,m,p;
	cin>>n>>m>>p;
	for(int i=1;i<=n;++i)
		f[i] = i;
	for(int i=0;i<m;++i)
	{
		int a,b;
		cin>>a>>b;
		link(a,b);
	}
	for(int i=0;i<p;++i)
	{
		int a,b;
		cin>>a>>b;
		if(check(a,b))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
