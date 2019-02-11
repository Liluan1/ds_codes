#include <stdc++.h>
using namespace std;
struct edge{
	int u,v,cost;
}; 

edge es[max_e];
int V,E;

bool cmp(edge& e1,edge& e2){
	return e1.cost < e2.cost;
}

int kruskal(){
	sort(es,es+E,cmp);
	init_nuion_find(V);
	int res = 0;
	for(int i=0;i<E;++i){
		edge e = es[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			res += e.cost;
		}
	}
	return res;
}
int main(){
	
	return 0;
} 
