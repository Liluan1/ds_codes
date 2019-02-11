#include<iostream>
using namespace std;
int main(){
	int k;
	cin>>k;
	for(int i=0;i<k;++i){
		int n,m;
		cin>>n>>m;
		if(n%(m+1) == 0)
			cout<<"Rabbit"<<endl;
		else
			cout<<"Grass"<<endl;
	}
	return 0;
} 
