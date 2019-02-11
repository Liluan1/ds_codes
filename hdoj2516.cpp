#include <iostream>
#include <set>
using namespace std;
int fib[100005];
int main(){
	set<int> s;
	fib[0] = 1;
	fib[1] = 1;
	for(int i=2;i<100000;++i){
		fib[i] = fib[i-1]+fib[i-2];
		s.insert(fib[i]);
	}
	int n;
	while(cin>>n && n!=0){
		if(s.count(n)>0)
			cout<<"Second win"<<endl;
		else
			cout<<"First win"<<endl;
	}
	return 0;
}
