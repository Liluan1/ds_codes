#include <iostream>
using namespace std;
int num;
int heap[1000005];

void insert(int ans){
	heap[++num] = ans;
	int n = num;
	if(n==1)
		return ;
	while(heap[n]<heap[n/2] && n>1){
		swap(heap[n],heap[n/2]);
		n = n/2;
	}
}

void print(){
	cout<<heap[1]<<endl;
}

void del(){
		int n = 1;
		heap[n] = heap[num];
		num--;
		while(2*n<=num){
			int t;
			if(2*n+1<=num && heap[n*2]>heap[n*2+1])
				t = n*2+1;
			else
				t = n*2;
			if(heap[n]>heap[t]){
				swap(heap[n],heap[t]);
				n = t;
			}
			else
				break;
			
		}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		int ans;
		cin>>ans;
		if(ans==1){
			cin>>ans;
			insert(ans);
		} 
		else if(ans==2)
			print();
		else
			del(); 
	}
	return 0;
} 
