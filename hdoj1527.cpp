#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int a,b;
	while(cin>>a>>b){
		if(a>b)
			swap(a,b);
		if(a == (int)((b-a)*(sqrt(5)+1)/2))
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}
}
