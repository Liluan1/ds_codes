#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000;
struct vertex{
	vector<vertex*> edge;
};
vertex G[maxn];

int main()
{
	int v,e;
	cin>>v>>e;
	for(int i=1;i<=v;++i){
		int s,t,w;
		cin>>s>>t>>w;
		G[s].edge.push_back(&G[t]);
		G[t].edge.push_back(&G[s]);
	}
	dfs(1);
	return 0;
 } 
