#include<iostream>
using namespace std;

int n,f[1010];
int a[1010];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[1]=a[1];
	f[2]=a[2];
	for(int i=3;i<=n;i++)
		for(int j=1;j<=i-2;j++)
			f[i]=max(f[i],f[j]+a[i]);
	cout<<max(f[n],f[n-1])<<endl; 
	return 0;
}
