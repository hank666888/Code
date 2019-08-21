#include<bits/stdc++.h>
using namespace std;

int a[101];
int x,n,s;

int sol(int x)
{
	int cnt;
	cnt=1;
	s=a[1];
	for(int i=2;i<=n;i++)
	{
		s=s+a[i];
		if(s>x)
		{
			cnt++;
			s=a[i];
		}
	}
	return cnt;
}

int main()
{
	int m,maxa=0; 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
		s=s+a[i];
	} 
	x=max(maxa,s/m);
	while(sol(x)>m) 
        x++;
	cout<<x<<endl;
	return 0;
}