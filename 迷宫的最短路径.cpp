#include <bits/stdc++.h>
using namespace std;
char a[105][105];
int d[105][105];
int n,m; 
typedef pair<int,int> P;
const int INF = 1<<30;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};


int bfs(int b,int c){
	queue<P> q;
	q.push(P(b,c));
	int x1,y1;
	while(!q.empty()){
		P p = q.front();
		x1 = p.first;
		y1 = p.second;
		q.pop();
		if(a[x1][y1] == 'G')
			break;
		for(int i=0;i<4;++i){
			int x = x1+dx[i], y = y1+dy[i];
			if(x>=0 && x<n && y>=0 && y<m && a[x][y]!='#' && d[x][y]==INF){
				q.push(P(x,y));
				d[x][y] = d[x1][y1]+1;
			}
		}
	}
	return d[x1][y1];
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			d[i][j] = INF;
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(a[i][j]=='S'){
				d[i][j] = 0;
				cout<<bfs(i,j);
				break;
			}
		}
	}
	return 0;
}
