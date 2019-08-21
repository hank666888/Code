//f[i]=Σ(f[j-1]*f[i-j])
//1<=j<=i
#include <iostream>
using namespace std;

int n;

long long f[31];

int main(){
	cin>>n;
	f[0]=1;
	f[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i;j++)
			f[i]+=f[j-1]*f[i-j];
	}
	cout<<f[n]<<endl;
	return 0;
}