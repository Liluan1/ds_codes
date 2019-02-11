#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,pos=0,num=0;
	string a;
	cin>>n>>a;
	while(pos!=0||!num){
		pos=a.find("xxx",pos)+1;
		num++;
	}
	cout<<num-1;
	return 0;
}
