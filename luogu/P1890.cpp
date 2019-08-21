#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n,m;

int a[10010];

int f[1010][1010];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
		f[i][i]=a[i];
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			f[i][j]=__gcd(f[i][j-1],a[j]);
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",f[l][r]);
	}
	return 0;
}