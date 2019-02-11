#include <iostream>
using namespace std;
const int maxn=100+5;
char pic[maxn][maxn];
int m,n,idx[maxn][maxn];
void dfs(int i,int j,int cnt)
{
	if(i<0||i>=m||j<0||j>=n)
		return ;
	if(idx[i][j]>0||pic[i][j]!='@')
		return ;
	idx[i][j]=cnt;
	for(int di=-1;di<=1;++di)
		for(int dj=-1;dj<=1;++dj)
			if(di!=0||dj!=0)
				dfs(i+di,j+dj,cnt);
}
int main()
{
	while(cin>>m>>n&&m&&n)
	{
		for(int i=0;i<m;++i)
			cin>>pic[i];
		int cnt=0;
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
				if(idx[i][j]==0&&pic[i][j]=='@')
					dfs(i,j,++cnt);
		cout<<cnt;
	}
	return 0;
} 
