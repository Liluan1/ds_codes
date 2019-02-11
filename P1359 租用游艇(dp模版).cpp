#include <iostream>
#include <string.h>
using namespace std;
int n; 
int a[205][205];
int d[205];
int dp(int i)
{
	int &ans = d[i];
	if(ans>0)
		return ans;
	ans=a[i][n];
	for(int j=i+1;j<=n;++j)
		if(a[i][j])
			ans = min(ans, dp(j)+a[i][j]);
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<n;++i)
		for(int j=1;j<n-i+1;++j)
			cin>>a[i][i+j];
//	cout<<a[1][2]<<' '<<a[1][3]<<' '<<a[2][3];
	memset(d,0,sizeof(d));
	cout<<dp(1);
	return 0;
}
