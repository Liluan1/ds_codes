#include <bits/stdc++.h>
using namespace std;
const int maxn = 400005;
const int INF = 1<<30;
struct edge{
	int from,to,w;
};
edge G[maxn];
int v,e;
int d[2505];
void bellman_ford(int s)
{
	for(int i=1;i<=v;++i)
		d[i] = INF;
	d[s] = 0;
	while(true){
		bool updata = false;
		for(int i=1;i<=2*e;++i){
			edge es = G[i];
			if(d[es.from]!=INF&&d[es.to]>d[es.from]+es.w){
				d[es.to]=d[es.from]+es.w;
				updata = true;
			}
		}
		if(!updata)
			break;
	}
}
int main()
{
	cin>>v>>e;
	for(int i=1;i<=2*e;i+=2){
		int s,t,w;
		cin>>s>>t>>w;
		edge ans;
		ans.from = s;
		ans.to = t;
		ans.w = w;
		G[i] = ans;
		ans.from = t;
		ans.to = s;
		G[i+1] = ans;
	}
	bellman_ford(1);
	cout<<d[v];
	return 0;
 } 
