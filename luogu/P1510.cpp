#include <iostream>
using namespace std;

int n,m,v;

int	c[10010],w[10010];

int f[10010];

int main(){
	cin>>m>>n>>v;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=v;j>=w[i];j--)
			f[j]=max(f[j],f[j-w[i]]+c[i]);
	}
	for(int i=1;i<=v;i++){
		if(f[i]>=m){
			cout<<v-i<<endl;
			return 0;
		}
	}
	cout<<"Impossible"<<endl;
	return 0;
}
