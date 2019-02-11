#include <bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,cost;
};
edge G[100005];
int f[20005];
int e[20005];

bool cmp(edge a,edge b){
	return a.cost>b.cost;
}

int fa(int a){
	return f[a] == a?a:f[a] = fa(f[a]);
}

bool check(int a,int b){
	return fa(a) == fa(b);
}

void link(int a,int b){
	if(!check(a,b))
		f[fa(a)] = fa(b);
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		f[i] = i;
	for(int i=0;i<m;++i){
		int a,b,c;
		cin>>a>>b>>c;
		G[i].from = a;
		G[i].to = b;
		G[i].cost = c;
	}
	sort(G,G+m,cmp);
	for(int i=0;i<=m;++i){
		edge ans = G[i];
		if(check(ans.from,ans.to)){
			cout<<ans.cost;
			break;
		}
		else{
			if(!e[ans.from])
				e[ans.from] = ans.to;
			else
				link(ans.to,e[ans.from]);
			if(!e[ans.to])
				e[ans.to] = ans.from;
			else
				link(ans.from,e[ans.to]);
		}
	}
	return 0;
 } 
