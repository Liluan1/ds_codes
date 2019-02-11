#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for(int i=0;i<m;++i){
		long long ans;
		cin>>ans;
		int lo=1,hi=n;
		while(lo<hi){
			int mi = (lo+hi)/2;
			if(ans<=a[mi])
				hi = mi;
			else
				lo = mi+1;
		}
		cout<<lo<<' '<<ans-a[lo-1]<<endl;
	}
	return 0;
}
