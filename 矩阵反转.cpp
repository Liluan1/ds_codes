#include<iostream>
using namespace std;
int s[200][200];
int main()
{
	int m,n,t;
	cin>>m>>n>>t;
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			cin>>s[i][j];
	if(t)
	{
		for(int i=m-1;i>=0;--i)
		{
			for(int j=0;j<n;++j)
				cout<<s[i][j]<<' ';
			cout<<endl;
		}
	}
	else
	{
		for(int i=0;i<m;++i)
		{
			for(int j=n-1;j>=0;--j)
				cout<<s[i][j]<<' ';
			cout<<endl;
		}
	}
	return 0;
} 
