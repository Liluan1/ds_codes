#include <bits/stdc++.h>
using namespace std;
const int INF = 1<<30;
int a[205];
double d[105];
struct edge{
	int from,to;
	double cost;
};
vector<edge> G;	
int v,e;

void bell(int s)
{
	for(int i=1;i<=v;++i)
		d[i] = INF;
	d[s]=0;
	while(true){
		bool update = false;
		for(int i=0;i<2*e;++i){
			edge e = G[i];
			if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost){
				d[e.to] = d[e.from]+e.cost;
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
	cin>>v;
	for(int i=1;i<=2*v;i+=2)
		cin>>a[i]>>a[i+1];
	cin>>e;
	for(int i=0;i<e;++i){
		int s,t;
		edge ans,ans1;
		cin>>s>>t;
		ans.from=s;
		ans1.to=s;
		ans1.from=t;
		ans.to=t;
		ans.cost=sqrt((a[2*t-1]-a[2*s-1])*(a[2*t-1]-a[2*s-1])+(a[2*t]-a[2*s])*(a[2*t]-a[2*s]));
		ans1.cost = ans.cost;
		G.push_back(ans);
		G.push_back(ans1);
	}
	cin>>from>>to;
	bell(from);
	printf("%.2lf",d[to]);
	return 0;
}
