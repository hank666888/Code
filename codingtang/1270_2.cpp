#include <iostream>
using namespace std;

int n,m,ans,G[100][100],rG[100][100],d1[100],d2[100];

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		G[a][b]=1;
		rG[b][a]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&G[i][k]&&G[k][j]){
					G[i][j]=1;
				}
				if(i!=j&&rG[i][k]&&rG[k][j]){
					rG[i][j]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(G[i][j])
				d1[i]++;
			if(rG[i][j])
				d2[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(d1[i]>=(n+1)/2||d2[i]>=(n+1)/2)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}