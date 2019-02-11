#include <bits/stdc++.h>
using namespace std;
int V,E;
long long d[105][105];
const int INF = 1<<30;

void floyd(){
	for(int k=1;k<=V;++k){
		for(int i=1;i<=V;++i){
			for(int j=1;j<=V;++j){
				d[i][j] = min(d[i][k]+d[k][j], d[i][j]);
			}
		} 
	}
}

int main(){
	cin>>V>>E;
	for(int i=1;i<=V;++i){
		for(int j=1;j<=V;++j){
				d[i][j] = INF;
		}
		d[i][i] = 0;
	}
	for(int i=0;i<E;++i){
		int s,t,w;
		cin>>s>>t>>w;
		d[s][t] = w;
	}
	floyd();
	cout<<d[1][V];
	return 0;
}
