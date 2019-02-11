#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//int a[10000005];
vector<int> a;
deque<int> q1;
deque<int> q2;


int main()
{
	int n,m,cnt = -1,maxn = -1,ans;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		int ans;
		cin>>ans;
		a.push_back(ans);
	}
	for(int i=0;i<n;++i){
		if(!q1.empty() && q1.back()>=m-1){
			cnt = a[q1.front()];
			if(q1.back()-q1.front()>=m-1)
				q1.pop_front();
		}
		while(!q1.empty() && a[q1.back()]<=a[i]){
			q1.pop_back();
		}
		q1.push_back(i);
		
		if(!q2.empty() && q2.back()>=m-1){
			cnt -= a[q2.front()];
			if(q2.back()-q2.front()>=m-1)
				q2.pop_front(); 
		}
		while(!q2.empty() && a[q2.back()]>=a[i]){
			q2.pop_back();
		}
		q2.push_back(i);
		maxn = max(maxn,cnt);
	}
	while(!q1.empty() || !q2.empty()){
		if(!q1.empty()){
//			cout<<q1.front()<<endl;
			cnt = a[q1.front()];
			q1.pop_front();
		}
		if(!q2.empty()){
//			cout<<q2.front()<<endl;
			cnt -= a[q2.front()];
			q2.pop_front();
		}
		maxn = max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
 } 
 
