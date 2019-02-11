#include<cstdio>

const int maxn=1e6;
struct list {
	int next,arr;
	long long len;
}edge[2*maxn+5];
long long sum[maxn+5],ans,n;
bool vis[maxn+5];
int head[maxn+5];

inline void linking(int u,int v,long long c,int size) {
	edge[size]={head[u],v,c}; head[u]=size;
	edge[size-1]={head[v],u,c}; head[v]=size-1;
}

inline long long abs(long long x) {
	return x<0?-x:x;
}

void dfs(int x) {
	vis[x]=1; sum[x]=1;
	for(int i=head[x];i;i=edge[i].next)
		if(!vis[edge[i].arr]) {
			dfs(edge[i].arr);
			ans+=edge[i].len*abs(n-2*sum[edge[i].arr]);
			sum[x]+=sum[edge[i].arr];
			//printf("%d %d %lld\n%lld\n",x,edge[i].arr,edge[i].len,ans);
		}
	//printf("%d %lld\n",x,sum[x]);
}

int main() {
	scanf("%d",&n);
	for(int u,v,c,i=1;i<n;i++) {
		scanf("%d %d %d",&u,&v,&c);
		linking(v,u,c,i*2); 
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
