#include <iostream>
#include <cstring>
using namespace std;

long long f[210],n,m;

long long a[21],b[21];

long long pow(long long a,long long b){
	long long sum=1;
	for(long long i=1;i<=b;i++)
		sum*=a;
	return sum;
}

int main(){
	memset(f,0x7f,sizeof(f));
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
	}
	f[0]=0;
	for(int i=1;i<=m;i++){
		for(int j=n;j>=1;j--){
			for(int x=0;x<=j;x++){
				f[j]=min(f[j],f[j-x]+a[i]*pow(x,b[i]));
			}
		}
	}
	cout<<f[n]<<endl;
	return 0;
}