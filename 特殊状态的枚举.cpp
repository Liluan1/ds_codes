#include <bits/stdc++.h>
using namespace std;
int a[100]; 
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	while(next_permutation(a,a+n)){
		for(int i=0;i<n;++i)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	
	return 0;
} 
