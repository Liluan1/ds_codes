#include <iostream>
#include <map>
using namespace std;
map<string,int> mp;
int f[20005];
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
	int n,m,k;
	string ans,ans1;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>ans;
		mp[ans]=i;
		f[i]=i;
	}
	for(int i=0;i<m;++i)
	{
		cin>>ans>>ans1;
		link(mp[ans],mp[ans1]);
	}
	cin>>k;
	for(int i=0;i<k;++i)
	{
		cin>>ans>>ans1;
		if(check(mp[ans],mp[ans1]))
			cout<<"Yes."<<endl;
		else
			cout<<"No."<<endl;
	}
	return 0;
 } 
