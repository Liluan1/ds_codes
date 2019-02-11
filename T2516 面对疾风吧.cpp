#include <iostream>
#include <algorithm>
using namespace std;
int arr[10005],b[10005];
bool mer(int a,int b)
{
	if(arr[a]!=arr[b])
		return arr[a]<arr[b];
	else
		return a<b;
}
int main()
{
	int n,k;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>arr[i];
		b[i]=i;
	}
	sort(b+1,b+n+1,mer);
	cin>>k;
	cout<<b[k];

}
