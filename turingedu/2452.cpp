#include<iostream>
using namespace std;

unsigned long long f[65];
int n;

int main(){
	cin>>n;
	f[1]=2;
	for(int i=2;i<=n;i++)
		f[i]=f[i-1]*2+2;
	cout<<f[n]<<endl;
	return 0;
} 
