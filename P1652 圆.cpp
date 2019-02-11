#include <iostream>
using namespace std;
int x[55],y[55],r[55];
int main()
{
	int n,x1,y1,x2,y2,num=0;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>x[i];
	for(int i=0;i<n;++i)
		cin>>y[i];
	for(int i=0;i<n;++i)
		cin>>r[i];
	cin>>x1>>y1>>x2>>y2;
	for(int i=0;i<n;++i)
	{
		if((x1-x[i])*(x1-x[i])+(y1-y[i])*(y1-y[i])<r[i]*r[i]&&(x2-x[i])*(x2-x[i])+(y2-y[i])*(y2-y[i])>r[i]*r[i])
			num++;
		if((x2-x[i])*(x2-x[i])+(y2-y[i])*(y2-y[i])<r[i]*r[i]&&(x1-x[i])*(x1-x[i])+(y1-y[i])*(y1-y[i])>r[i]*r[i])
			num++;
	}
	cout<<num;
	return 0;
}
