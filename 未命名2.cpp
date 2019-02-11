#include<bits/stdc++.h>
using namespace std;
const int mxn=1e5+10;
int n,m;
int f[mxn],v[mxn],ch[mxn][2],dis[mxn]; 
int get(int x){//不用路径压缩,不赋初值，所以他祖先没有父亲(为0 
    while(f[x])x=f[x];//一直找,直到这个节点没父亲即为祖先 
    return x;
}
int merge(int x,int y){//返回值为编号，是直接父亲的编号 
    if(x==0||y==0)return x+y;
    if(v[x]>v[y]||(v[x]==v[y]&&x>y))swap(x,y);
    ch[x][1]=merge(ch[x][1],y);
    f[ch[x][1]]=x;
    if(dis[ch[x][0]]<dis[ch[x][1]])swap(ch[x][1],ch[x][0]);//维持左偏性质 
    dis[x]=dis[ch[x][1]]+1;return x;
    //因为是左偏树,所以右边的深度要小,左边深度要大
    //所以维护距离时,以右儿子为标准统计深度 
}
void pop(int x){
    v[x]=-1;
    f[ch[x][0]]=f[ch[x][1]]=0;
    merge(ch[x][0],ch[x][1]);
}
int main(){
	freopen("testdata.in","r",stdin);
	freopen("testdata2.out","w",stdout);
    scanf("%d%d",&n,&m);
    dis[0]=-1;
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    for(int i=1;i<=m;i++){
        int opt;
        scanf("%d",&opt);
        if(opt==1){
            int x,y;
            scanf("%d%d",&x,&y);
            if(v[x]==-1||v[y]==-1)continue;//有一个节点被删除惹
            int fx=get(x),fy=get(y);
            if(fx==fy)continue;//本来就在一个堆里
            merge(fx,fy);
        }
        else{
            int x;
            scanf("%d",&x);
            if(v[x]==-1)//puts("-1");
            	cout<<-1<<' '<<x<<endl;
            else{
                int fx=get(x);
                printf("%d %d\n",v[fx],fx);
                pop(fx);
            }
        }
    } 
}
