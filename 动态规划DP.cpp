#include <stdc++.h>
using namespace std;
int dp[max][max];

int rec(int i,int j){
	if(dp[i][j]>=0)
		return dp[i][j];
	int res;
	if(i==n)
		res = 0;
	else if(j<w[i]){
		rec(i+1,j);
	}
	else
		res = max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
	return res;
}

void solve(){
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,W);
}
int main(){
	return 0;
} 
