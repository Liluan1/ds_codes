#include<bits/stdc++.h>
using namespace std;
const int mxn=1e5+10;
int n,m;
int f[mxn],v[mxn],ch[mxn][2],dis[mxn]; 
int get(int x){//����·��ѹ��,������ֵ������������û�и���(Ϊ0 
    while(f[x])x=f[x];//һֱ��,ֱ������ڵ�û���׼�Ϊ���� 
    return x;
}
int merge(int x,int y){//����ֵΪ��ţ���ֱ�Ӹ��׵ı�� 
    if(x==0||y==0)return x+y;
    if(v[x]>v[y]||(v[x]==v[y]&&x>y))swap(x,y);
    ch[x][1]=merge(ch[x][1],y);
    f[ch[x][1]]=x;
    if(dis[ch[x][0]]<dis[ch[x][1]])swap(ch[x][1],ch[x][0]);//ά����ƫ���� 
    dis[x]=dis[ch[x][1]]+1;return x;
    //��Ϊ����ƫ��,�����ұߵ����ҪС,������Ҫ��
    //����ά������ʱ,���Ҷ���Ϊ��׼ͳ����� 
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
            if(v[x]==-1||v[y]==-1)continue;//��һ���ڵ㱻ɾ����
            int fx=get(x),fy=get(y);
            if(fx==fy)continue;//��������һ������
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
