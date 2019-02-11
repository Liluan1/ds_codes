#include <bits/stdc++.h>
using namespace std;
const int INF = 1<<30;
const int cnt = 9987;
int d[1005];
struct edge{
	int from,to;
	int cost;
};
vector<edge> G;	
int v,e;

void bell(int s)
{
	for(int i=1;i<=v;++i)
		d[i] = INF;
	d[s]=1;
	while(true){
		bool update = false;
		for(int i=0;i<e;++i){
			edge e = G[i];
			if(d[e.from]!=INF&&d[e.to]>d[e.from]%cnt*e.cost%cnt){
				d[e.to] = d[e.from]%cnt*e.cost%cnt;
				update = true;
			}
		}
		if(!update)
			break;
	}
}
int main()
{
	int from,to;
	cin>>v>>e;
	for(int i=0;i<e;++i){
		int s,t,w;
		edge ans;
		cin>>s>>t>>w;
		ans.from=s;
		ans.to=t;
		ans.cost = w;
		G.push_back(ans);
	}
	bell(1);
	cout<<d[v];
	return 0;
}
