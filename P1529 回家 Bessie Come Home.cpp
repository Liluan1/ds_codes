#include <bits/stdc++.h>
using namespace std;
const int INF = 1<<30;
struct edge{
	char from,to;
	int w;
};
vector<edge> G;
char a[55];
int d[55];
void bellman_ford(int s)
{
	for(int i=0;i<55;++i)
		d[i] = INF;
	d[s] = 0;
	while(true){
		bool updata = false;
		for(int i=0;i<G.size();++i){
			edge ans;
			ans = G[i];
			if(d[ans.from]!=INF&&d[ans.to]>d[ans.from]+ans.w){
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
	int e,minn = INF;
	char cnt; 
	cin>>e;
	for(int i=0;i<26;++i)
		a[i] = 'A'+i;
	for(int i=26;i<52;++i)
		a[i] = 'a'+i-26;
	for(int i=0;i<e;++i){
		char ans1,ans2;
		int s,t,w;
		cin>>ans1>>ans2>>w;
		if(ans1<='Z')
			s = ans1-'A';
		else
			s = ans1-'a'+26;
		if(ans2<='Z')
			t = ans2-'A';
		else
			t = ans2-'a'+26;
		edge ans;
		ans.from = s;
		ans.to = t;
		ans.w = w;
		G.push_back(ans);
		ans.from = t;
		ans.to = s;
		G.push_back(ans);
	}
	for(int i=0;i<G.size();++i){
		edge ans;
		ans = G[i];
		if(a[ans.from]<'Z'){
			bellman_ford(ans.from);
			if(d[25]<minn){
				minn = d[25];
				cnt = a[ans.from];
			}
		}	
		if(a[ans.to]<'Z'){
			bellman_ford(ans.to);
			if(d[25]<minn){
				minn = d[25];
				cnt = a[ans.to];
			}
		}
	}
	cout<<cnt<<' '<<minn; 
	return 0;
 } 
