#include <bits/stdc++.h>
using namespace std;
int main()
{
	char c;
	while((c=getchar())!='\n'){
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
			if((c>='w'&&c<='z')||(c>='W'&&c<='Z'))
				c=c-22;
			else
				c=c+4;
		}
		else{
			cout<<"asfdf"<<endl;
			c=getchar();
		}
		cout<<c<<endl;
	}
	return 0;
 } 
