#include <iostream>
using namespace std;
int n,m;
char a[105][105];

void dfs(int b,int c){
	a[b][c] = '.';
	for(int i=-1;i<=1;++i){
		for(int j=-1;j<=1;++j){
			int x=b+i,y=c+j;
			if(x>=0 && x<n && y>=0 && y<m && a[x][y]=='W')
				dfs(x,y);
		}
	}
}

int main(){
	int cnt=0;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(a[i][j]=='W'){
				dfs(i,j);
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
