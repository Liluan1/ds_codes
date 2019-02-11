#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	double s,a,b;
	cin>>s>>a>>b;
	double x=2*a*s/(3*a+b); 
	double t=(s-x)/b+x/a;
	printf("%.6lf",t); 
	return 0;
 } 
