 #include<iostream>
using namespace std;

long long n,V,w[110];
long long f[10010];

int main(){
    cin>>n>>V;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=w[i];j<=V;j++)
			f[j]+=f[j-w[i]];
	cout<<f[V]<<endl;
	return 0;
}

