#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
vector<int> G[maxn];
int used[maxn];
int col[maxn];
int white,black;

bool dfs(int t,int color){
	if(used[t]){
		if(color == col[t])
			return true;
		else
			return false;
	}
	else{
		used[t] = 1;
		col[t] = color;
		if(color)
			black++;
		else
			white++;
		bool ans = true;
		for(int i=0;i<G[t].size();++i){
			ans = dfs(G[t][i],1-color);
			if(!ans)
				break;
		}
		return ans;
	}
}

int main()
{
	int n,m,sum = 0;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bool ans;
	for(int i=1;i<=n;++i){
		white = black = 0;
		if(!used[i])
			ans = dfs(i,0);
		if(!ans)
			break;
		sum += min(white,black);
	}
	if(!ans)
		cout<<"Impossible";
	else
		cout<<sum;
	return 0;
}
