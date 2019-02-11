#include <bits/stdc++.h>
using namespace std;
int f[200005];
int l[200005];
int minn = 1<<30;

int fa(int a){
	if(f[a] != a){
		int father = f[a];
		f[a] = fa(f[a]);
		l[a] += l[father];
	}
	return f[a];
}

bool check(int a,int b){
	return fa(a) == fa(b);
}

void link(int a,int b){
	if(!check(a,b)){
		f[fa(a)] = fa(b);
		l[a] = l[b]+1;
	}
	else
		minn = min(minn,l[a]+l[b]+1);
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		f[i] = i;
	for(int i=1;i<=n;++i){
		int ans;
		cin>>ans;
		link(i,ans);
	}
	cout<<minn;
	return 0;
}
