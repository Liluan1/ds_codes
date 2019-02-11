#include <iostream>
#include <map>
using namespace std;
int d[100],code[100];
char c[100];
map<char,string> m;
struct btnode{
	char ch;
	btnode *lc,*rc;
	int data;
};

btnode *createhuffman(int n){
	btnode *b[100],*p;
	for(int i=0;i<n;++i){
		b[i] = new btnode;
		b[i]->data = d[i];
		b[i]->ch = c[i];
		b[i]->lc = b[i]->rc = NULL;
	}
	for(int i=0;i<n-1;++i){
		int k1=-1,k2;
		for(int j=0;j<n;++j){
			if(b[j]!=NULL && k1==-1){
				k1 = j;
				continue;
			}
			if(b[j]!=NULL){
				k2 = j;
				break;
			}
		}
		for(int j=k2;j<n;++j){
			if(b[j]!=NULL){
				if(b[j]->data < b[k1]->data){
					k2 = k1;
					k1 = j;
				}
				else if(b[j]->data < b[k2]->data){
					k2 = j;
				}
			}
		}
		p = new btnode;
		p->data = b[k1]->data + b[k2]->data;
		p->lc = b[k1];
		p->rc = b[k2];
		b[k1] = p;
		b[k2] = NULL;
	}
	return p;
}

void huffmancode(btnode *p,int len){
	if(p==NULL)
		return ;
	if(p->lc==NULL && p->rc==NULL){
		string str;
		for(int i=0;i<len;++i)
			str += '0'+code[i];
		m[p->ch] = str;
	}
	else{
		code[len] = 0;
		huffmancode(p->lc,len+1);
		code[len] = 1;
		huffmancode(p->rc,len+1);
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>c[i];
	}
	for(int i=0;i<n;++i){
		cin>>d[i];
	}
	btnode *p = createhuffman(n);
	huffmancode(p,0);
	for(int i=0;i<n;++i)
		cout<<c[i]<<':'<<m[c[i]]<<endl;
	return 0;
} 
