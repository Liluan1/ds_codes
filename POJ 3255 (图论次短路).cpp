#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P; 
struct edge{
	int to, cost;
};
vector<edge> G[5005];
int dist[5005];
int dist2[5005];
int V, E;
const int INF = 1<<30;

void solve(){
	priority_queue<P, vector<P>, greater<P> > que;
	fill(dist, dist+V, INF);
	fill(dist2, dist2+V, INF);
	dist[0] = 0;
	que.push(P(0,0));
	while(!que.empty()){
		P p = que.top();
		que.pop();
		int v = p.second, d = p.first;
		if(dist2[v] < d)
			continue;
		for(int i=0;i<G[v].size();++i){
			edge e = G[v][i];
			int d2 = d + e.cost;
			if(d2 < dist[e.to]){
				swap(d2, dist[e.to]);
				que.push(P(dist[e.to], e.to));
			}
			if(d2 < dist2[e.to] && d2 > dist[e.to]){
				dist2[e.to] = d2;
				que.push(P(dist2[e.to], e.to));
			}
		}
	}
}

int main(){
	cin>>V>>E;
	for(int i=0;i<E;++i){
		int s,t,w;
		cin>>s>>t>>w;
		s -= 1;
		t -= 1;
		edge e;
		e.to = t;
		e.cost = w;
		G[s].push_back(e);
		e.to = s;
		G[t].push_back(e);
	}
	solve();

	cout<<dist2[V-1];
	return 0;
}
