#include<iostream>
using namespace std;

int n,p[4],x[4];

int main(){
	cin>>n;
	int ans=1e9;
	for(int i=1;i<=3;i++)
		cin>>p[i]>>x[i];
	for(int i=1;i<=3;i++)
		ans=min(ans,((n+p[i]-1)/p[i])*x[i]);
	cout<<ans<<endl;
	return 0; 
} 
