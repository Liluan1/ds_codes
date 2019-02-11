#include <bits/stdc++.h>
using namespace std;
int v,e;
int d[105];
bool used[105];
int cost[105][105];

void dij(int s){
	fill(d, d+v, INF);
	fill(used, used+v, false);
	d[s] = 0;
	while(true){
		int v1 = -1;
		for(int u=0;u<v;++u){
			if(!used[u] && (v1==-1 || d[u]<d[v1]))
				v1 = u;
		}
		if(v1==-1)
			break;
			
		used[v1] = true;
		for(int u=0;u<v;++u){
			d[u] = min(d[u], d[v]+cost[u][v]);
		}
	}
}

int main(){
	cin>>v>>e;
	for(int i=0;i<e;++i){
		int s,t,w;
		cin>>s>>t>>w;
		cost[s][t] = w;
	} 
	
	return 0;
}
