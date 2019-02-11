#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
const int INF = 1<<30;
int main()
{
	int n,cnt=0,minn = INF;
	cin>>n;
	if(n<=2)
		cout<<0;
	else{
		bool ans;
		for(int i=1;i<=n;++i)
			cin>>b[i];
		for(int i=-1;i<=1;++i){
			a[1] = b[1]+i;
			for(int j=-1;j<=1;++j){
				ans = true;
				cnt = 0;
				a[2] = b[2]+j;
				for(int k=3;k<=n;++k){
					a[k] = a[1]+(k-1)*(a[2]-a[1]);
					if(abs(a[k]-b[k])>1){
						ans = false;
						break;	
					}
					else if(a[k]!=b[k])
						cnt++;
				}
				if(ans){
					if(i)
						cnt++;
					if(j)
						cnt++;
					minn = min(minn,cnt);
				}
			}
		}
		if(minn==INF)
			cout<<-1;
		else
			cout<<minn;
	}
	return 0; 
 } 
