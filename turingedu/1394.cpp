#include<bits/stdc++.h>
using namespace std;

int n,m,ans;
int p[5001],a[5001];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>p[i]>>a[i];
	for(int i=m;i>=2;i--)
	{
		for(int j=i-1;j<=m;j++)
		{
			if(p[j]>p[j+1])
			{
				swap(p[j],p[j+1]);
				swap(a[j],a[j+1]);
			}
		}
	}
	int i=0;
	while(n>0)
	{
		i++;
		if(a[i]<=n)
		{
			ans+=p[i]*a[i];
			n-=a[i];	
		}
		else
		{
			ans+=n*p[i];
			n=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}