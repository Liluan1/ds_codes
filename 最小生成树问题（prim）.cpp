#include <bits/stdc++.h>
using namespace std;
int d[105][105];
bool used[105];
int mind[105];
int V,E;
const int INF = 1<<30;

int prim(){
	fill(mind,mind+V+1,INF);
	fill(used,used+V+1,false);
	mind[1] = 0;
	int res = 0;
	while(true){
		int v = -1;
		for(int i=1;i<=V;++i){
			if(!used[i] && (v == -1 || mind[i]<mind[v]))
				v = i;
		}
		
		if(v == -1)
			break;
		used[v] = true;
		res += mind[v];
		cout<<mind[v]<<' ';
		
		for(int i=1;i<=V;++i){
			mind[i] = min(mind[i], d[v][i]);
		}
	}
	return res;
} 

int main(){
	cin>>V>>E;
	for(int i=1;i<=V;++i){
		for(int j=1;j<=V;++j){
			d[i][j] = INF;
		} 
	} 
	for(int i=0;i<E;++i){
		int s,t,w;
		cin>>s>>t>>w;
		d[s][t] = w;
	}
	cout<<prim();
}
