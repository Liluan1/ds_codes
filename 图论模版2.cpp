#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000;
struct edge{
	int to,cost;
};
vector<edge> G[maxn];
int main()
{
	int v,e;
	cin>>v>>e;
	for(int i=1;i<=e;++i){
		int s,t,w;
		cin>>s>>t>>w;
		edge ans;
		ans.cost = w;
		ans.to = t;
		G[s].push_back(ans);
		ans.to = s;
		G[t].push_back(ans);
	}
	return 0;
 } 
