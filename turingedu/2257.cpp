#include <iostream>
using namespace std;

int f[1000010],a[1000010],n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[1]=a[1],f[2]=a[2],f[3]=f[1]+a[3];
	for(int i=4;i<=n;i++)
		f[i]=max(f[i-2],f[i-3])+a[i];
	cout<<max(f[n],f[n-1])<<endl;
	return 0;
}