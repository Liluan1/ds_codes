#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
struct vertex{
	vector<int> edge;
	int w;
};
int v;
vertex G[105];
int d[105];
int sum;
void dfs(int s,int f)
{
	d[s] = 1;
	sum+=f*G[s].w;
//	cout<<sum<<' '<<s<<' '<<f<<' '<<G[s].w<<endl;
	for(int i=0;i<G[s].edge.size();++i)
		if(G[s].edge[i]&&!d[G[s].edge[i]]){
//			d[G[s].edge[i]] = 1;
			dfs(G[s].edge[i],f+1);
		}	
	return;
}

int main()
{
	int minn = 1<<30;
	cin>>v;
//	cout<<v;
	for(int i=1;i<=v;++i){
		int w,s,t;
		cin>>w>>s>>t;
		G[i].w = w;
		G[i].edge.push_back(s);
		G[s].edge.push_back(i); 
		G[i].edge.push_back(t);
		G[t].edge.push_back(i);
	}
	for(int i=1;i<=v;++i){
		dfs(i,0);
		minn = min(minn,sum);
		sum = 0;
		memset(d,0,sizeof(d));
	}
	cout<<minn;
	return 0;
 } 
