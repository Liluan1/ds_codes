#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int N,M;
char field[maxn][maxn];

void dfs(int x,int y){
	field[x][y] = '.';
	
	for(int i=-1;i<=1;++i){
		for(int j=-1;j<=1;++j){
			int a = x+i, b = y+j;
			if(a>=0 && a<N && b>=0 && b<M && field[a][b] == 'W')
				dfs(a,b); 
		}
	}
	return ;
} 

int main(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;j++)
			cin>>field[i][j];
	}
	int ans = 0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(field[i][j] == 'W'){
				dfs(i,j);
				ans++; 
			}
		}
	}
	cout<<ans;
	return 0;
}
