#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[10005];
	gets(a);
	int len = strlen(a)-1;
	while(a[len]==' ')
		len-=1;
	if(len==-1)
		cout<<'0';
	for(int i=len;i>=0;--i)
	{
		if(a[i]==' ')
		{ 
			cout<<len-i;
			break;
		}
		else if(i==0)
			cout<<len+1;
			
	}
	return 0;
} 
