#include <iostream>
using namespace std;
struct node{
	node *lc,*rc,*f;
	int w,d,k;
	bool visited;
}; 
	
node *p[100005];

node *merge(node *x,node *y){
	if(!x)
		return y;
	if(!y)
		return x;
	if(x->w > y->w || (x->w==y->w&&x->k > y->k))
		swap(x,y);
	x->rc = merge(x->rc,y);
	x->rc->f = x;
	if(!x->lc || x->lc->d < x->rc->d)
		swap(x->lc,x->rc);
	if(x->rc==NULL)
		x->d = 0;
	else
		x->d = x->rc->d + 1;
	return x;
}

node *root(node *x){
	while(x->f)
		x = x->f;
	return x;
}

void pop(node *x){
	x->visited = true;
	if(x->lc)
		x->lc->f = NULL;
	if(x->rc)
		x->rc->f = NULL;
	merge(x->lc,x->rc);
	delete x;
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		int num;
		cin>>num;
		p[i] = new node;
		p[i]->w = num;
		p[i]->lc = NULL;
		p[i]->rc = NULL;
		p[i]->d = 0;
		p[i]->f = NULL;
		p[i]->visited = false;
		p[i]->k = i;
	}
	for(int i=0;i<m;++i){
		int a;
		cin>>a;
		if(a==1){
			int x,y;
			cin>>x>>y;
			if(p[x]->visited||p[y]->visited)
				continue;
			node *p1 = root(p[x]);
			node *p2 = root(p[y]);
			if(p1==p2)
				continue; 
			merge(p2,p1);
		}
		else{
			int x;
			cin>>x;
			if(p[x]->visited){
				cout<<-1<<endl;
			}
			else{
				node *p1 = root(p[x]);
				cout<<p1->w<<endl;
				pop(p1);
			}
		}
	}
	return 0;
} 
