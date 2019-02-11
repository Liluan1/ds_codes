#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int x1,y1,x2,y2;
		double sum=0;
		cin>>x1>>y1>>x2>>y2;
		if(x2+y2<x1+y1){
			swap(x1,x2);
			swap(y1,y2);
		}
		for(int j=x1+y1;j<x2+y2;++j)
		{
			sum+=j*sqrt(2)+sqrt(j*j+(j+1)*(j+1));
		}
		sum-=x1*sqrt(2);
		sum+=x2*sqrt(2);
		printf("%.3lf\n",sum); 
	}
	return 0;
}
