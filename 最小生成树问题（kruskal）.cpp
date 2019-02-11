#include <bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
};

edge es[105];
int V,E;
const int INF = 1<<30;
int f[105]; 

bool cmp(edge a,edge b){
	return a.w<b.w;
}

void init(){
	for(int i=1;i<=V;++i)
		f[i] = i;
} 

int fa(int a){
	return f[a]==a?a:f[a]=fa(f[a]);
}

bool visited(int a,int b){
	int a1 = fa(a);
	int b1 = fa(b);
	if(a1 == b1)
		return true;
	else
		return false; 
}

void link(int a,int b){
	if(!visited(a,b))
		f[fa(a)] = f[b];
}

int kruskal(){
	sort(es,es+E,cmp);
	init();
	int res = 0;
	for(int i=0;i<E;++i){
		edge e = es[i];
		if(!visited(e.u,e.v)){
			link(e.u,e.v);
			res += e.w;
		}
	} 
	return res;
}

int main(){
	cin>>V>>E;
	for(int i=0;i<E;++i){
		int s,t,w;
		cin>>s>>t>>w;
		edge e;
		e.u = s;
		e.v = t;
		e.w = w;
		es[i] = e;
	}
	cout<<kruskal();
	return 0;
}
