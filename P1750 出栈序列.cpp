#include <bits/stdc++.h>
using namespace std;
int a[10005];
int used[10005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	int l = 1,r = m,cnt;
	while(l<=r){
		bool update = false;
		int minn = 2e9+1;
		for(int i=l;i<=r;++i){
			if(a[i]<minn && !used[i]){
				minn = a[i];
				cnt = i;
				update = true;
			}
		}
		if(!update)
			break;
		used[cnt] = 1;
		cout<<a[cnt]<<' ';
		l = cnt+1;
		if(r<n)
			r++;
		for(int i=cnt-1;i>=1;--i){
			if(!used[i]){
				l = i;
				break;
			}
		}
	}
//	if(!used[l])
//		cout<<a[l]<<' ';
	return 0;
 } 
