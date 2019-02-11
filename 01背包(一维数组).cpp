#include <iostream>
#include <string.h>
using namespace std;
int w[1000],v[1000],dp[1000];
int main(){
	int T;
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		int n,W;
		cin>>n>>W;
		for(int i=0;i<n;++i){
			cin>>v[i];
		}
		for(int i=0;i<n;++i){
			cin>>w[i];
		}
		for(int i=0;i<n;++i){
			for(int j=W;j>=w[i];--j){
				dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
			}
		}
		cout<<dp[W]<<endl;
	}
	return 0;
} 
/*0 0 0 0 0 0 0 0 0 0
*/
  

