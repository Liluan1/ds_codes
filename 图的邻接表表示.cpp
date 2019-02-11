#include <bits/stdc++.h>
using namespace std;
struct vertex{
	vector<vertex *> edge;
	int w;
};

vertex G[1005];

int main(){
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;++i){
		int s,t;
		cin>>s>>t;
		G[s].edge.push_back(&G[t]);
		G[t].edge.push_back(&G[s]);
	}
	return 0;
}
