#include <bits/stdc++.h>
using namespace std;
int a[55];
int b[1005];
int c[55]; 
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=n;i>0;--i){
		if(!b[a[i]]){
			b[a[i]] = 1;
			c[ans]=a[i];
			ans++;
		}
	}
	cout<<ans<<endl;
	for(int i=ans-1;i>=0;--i)
		cout<<c[i]<<' '; 
	return 0;	
 } 
