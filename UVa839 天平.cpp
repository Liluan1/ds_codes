#include <iostream>
using namespace std;
bool check(int &w)
{
	int w1,w2,d1,d2;
	bool a=true,b=true;
	cin>>w1>>d1>>w2>>d2;
	if(!w1)
		a=check(w1);
	if(!w2)
		b=check(w2);
	w=w1+w2;
	return a&&b&&(w1*d1==w2*d2);
}
int main()
{
	int t,w;
	cin>>t;
	while(t--)
	{
		if(check(w))
			cout<<"Yes";
		else 
			cout<<"No";
		if(t)
			cout<<endl;
	}
	return 0;
 } 
