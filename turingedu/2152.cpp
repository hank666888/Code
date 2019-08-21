#include<bits/stdc++.h>
using namespace std;

long long n,m,ans;
int p[5001],a[5001];

int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++) cin>>p[i]>>a[i];
	for(int i=m;i>=2;i--)
	{
		for(int j=1;j<=i-1;j++)
		{
			if(p[j]>p[j+1])
			{
				swap(p[j],p[j+1]);
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		if(p[i]*a[i]<n)
		{
			ans+=a[i];
			n-=a[i]*p[i];	
		}
		else
		{
			ans+=n/p[i];
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}