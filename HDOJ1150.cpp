#include <iostream>
#include <string.h>
using namespace std;
bool line[505][505];
bool used[505];
int girl[505];
int m,n;
bool find(int x){
	for(int i=1;i<=n;++i){
		if(line[x][i]&&!used[i]){
			used[i] = true;
			if(girl[i]==0||find(girl[i])){
				girl[i] = x;
				return true;
			}
		}
	}
	return false;
}

int main(){
	m=1;
	int k;
	while(true){
		memset(line,0,sizeof(line));
		memset(girl,0,sizeof(girl)); 
		int max=0;	 
		cin>>m;
		if(!m)
			break;
		cin>>n>>k;
		for(int i=0;i<k;++i){
			int a,b,c;
			cin>>a>>b>>c;
			line[b][c] = true;
		}
		for(int i=1;i<=m;++i){
			memset(used,0,sizeof(used));
			if(find(i))
				max++;
		}
		cout<<max<<endl;
	}
	return 0;
} 
