#include <bits/stdc++.h>
using namespace std;
int a[6]={100,50,10,5,2,1};
int main()
{
	int n;
	while(cin>>n&&n){
		for(int i=0;i<n;++i)
		{
			int ans,num=0;
			cin>>ans;
			for(int j=0;j<6;++j)
			{
				while(ans>=a[j]){
					num++;
					ans-=a[j];
				}
				if(!ans)
					break;
			}
			cout<<num<<' ';
		}
		cout<<endl;
	}
	return 0;
 } 
