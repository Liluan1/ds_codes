#include <iostream>
using namespace std;
int dp[100][100];
int main(){
	string str1,str2;
	cin>>str1>>str2;
	int n = str1.length();
	int m = str2.length();
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(str1[i]==str2[j])
				dp[i+1][j+1] = dp[i][j]+1;
			else
				dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
		}
	}
	cout<<dp[n][m];
	return 0;
} 
