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
	f[2]=2;
	for(int i=3;i<=n;i++){
		for(int j=0;j<=i-2;j++)
			f[i]+=f[j]*f[i-j-2];
		f[i]+=f[i-1];
	}
	cout<<f[n]<<endl;
	return 0;
}