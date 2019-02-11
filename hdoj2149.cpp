#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int m,n;
	while(cin>>m>>n){
		if(n>=m){
			for(int i=m;i<=n;++i){
				if(i==n)
					cout<<i<<endl;
				else
					cout<<i<<' ';
			}
		}
		else if(m%(n+1) == 0)
			cout<<"none"<<endl;
		else{
			int first = 1;
			for(int i=1;i<=n;++i){
				if((m-i)%(n+1) == 0){
					if(first){
						first = 0;
						cout<<i;
					}
					else
						cout<<' '<<i;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}

