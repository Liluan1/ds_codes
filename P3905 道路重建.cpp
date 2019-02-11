#include <bits/stdc++.h>
using namespace std;
const int n = 105;
const int INF = 1<<30;
struct edge{
	int from,to,w;
};
vector<edge> G;
int v,e,m;
int a[105][105],d[105];

void bellman_ford(int s)
{
	for(int i=1;i<=v;++i)
		d[i] = INF;
	d[s] = 0;
	while(true){
		bool updata = false;
		for(int i=0;i<G.size();++i){
			edge ans;
			ans = G[i];
			if(d[ans.from]!=INF && d[ans.to]>d[ans.from]+ans.w){
				d[ans.to]=d[ans.from]+ans.w;
				updata = true;
			}
		}
		if(!updata)
			break;
	}
}

int main()
{
	int from,to,sum=0;
	cin>>v>>e;
	for(int i=0;i<e;++i){
		int s,t,w;
		cin>>s>>t>>w;
		edge ans;
		ans.from = s;
		ans.to = t;
		ans.w = 0;
		a[s][t] = w;
		a[t][s] = w;
		G.push_back(ans);
		ans.to = s;
		ans.from = t;
		G.push_back(ans);
	}
	cin>>m;
	for(int i=0;i<m;++i){
		int ans1,ans2;
		cin>>ans1>>ans2;
		for(int i=0;i<G.size();++i){
			if((G[i].from==ans1&&G[i].to==ans2)||(G[i].from==ans2&&G[i].to==ans1))
				G[i].w = a[ans1][ans2];
		}
	}
	cin>>from>>to;
	bellman_ford(from);
	cout<<d[to];
	return 0;
}
 
