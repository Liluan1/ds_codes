#include <iostream>
using namespace std;
int num,heap[10005];

void insert(int ans){
	heap[++num] = ans;
	int n = num;
	while(n>1){
		if(heap[n]<heap[n/2])
			swap(heap[n],heap[n/2]);
		else
			break;
		n = n/2;
	}
}

int pop(){
	int res = heap[1];
	heap[1] = heap[num--];
	int n = 1;
	while(2*n<=num){
		int t;
		if(2*n+1<=num && heap[2*n+1]<heap[2*n])
			t = 2*n+1;
		else
			t = 2*n;
		if(heap[n]>heap[t])
			swap(heap[n],heap[t]);
		else
			break;
		n = t;
	}
	return res;
}

int main(){
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;++i){
		int ans;
		cin>>ans;
		insert(ans);
	}
	while(num>=2){
		int a = pop();
		int b = pop();
		insert(a+b);
		sum+=(a+b);
	}
	cout<<sum;
	return 0;
}

