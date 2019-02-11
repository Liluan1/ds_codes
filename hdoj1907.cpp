#include <iostream>
using namespace std;
int main(){
	int k;
	cin>>k;
	for(int i=0;i<k;++i){
		int n,val1=0,key=0;
		cin>>n;
		for(int j=0;j<n;++j){
			int val;
			cin>>val;
			if(val>1)
				key = 1;
			val1 ^= val;
		} 
		if(key){
			if(val1)
				cout<<"John"<<endl;
			else
				cout<<"Brother"<<endl;
		}
		else{
			if(n%2==0)
				cout<<"John"<<endl;
			else
				cout<<"Brother"<<endl;
		}
	} 
	return 0;
}
//011 101 001
//110
