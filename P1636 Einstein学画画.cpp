#include <iostream>
using namespace std;
int t[1005];
int main()
{
	int n,m,a,b,num=0;
	cin>>n>>m;
	for(int i=0;i<m;++i)
	{
		cin>>a>>b;
		t[a]++;
		t[b]++;
	}
	for(int i=1;i<=n;++i)
		if(t[i]%2)
			num++;
	if(num)
		cout<<num/2;
	else
		cout<<1;
	return 0;
}
