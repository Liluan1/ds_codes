#include <bits/stdc++.h>
using namespace std;
struct edge{
	int to,cost;
};
typedef pair<int,int> P;

int V,E;
vector<edge> G[105];
int d[105];
const int INF = 1<<30;

void dij(int s){
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d,d+V+1,INF);
	d[s] = 0;
	que.push(P(0,s));
	while(!que.empty()){
		P p = que.top();
		que.pop();
		int v = p.second; 
		if(d[v] < p.first)
			continue;
		for(int i=0;i<G[v].size();++i){
			edge e = G[v][i];
			cout<<e.to<<' '<<e.cost<<endl;
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
} 

int main(){
	cin>>V>>E;
	for(int i=0;i<E;++i){
		int s,t,w;
		cin>>s>>t>>w;
		edge e;
		e.to = t;
		e.cost = w;
		G[s].push_back(e);
	}
	dij(1);
	cout<<d[V];
	return 0;
}
