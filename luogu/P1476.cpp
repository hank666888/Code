#include <iostream>
using namespace std;

const int INF=1e8;

int dis[110][110];

int n,m;

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		dis[u][v]=c;
	}
	for(int k=1;k<=n+1;k++)
		for(int i=1;i<=n+1;i++)
			for(int j=1;j<=n+1;j++)
				if(i!=j&&j!=k&&i!=k&&dis[i][k]&&dis[k][j])
					dis[i][j]=max(dis[i][j],dis[i][k]+dis[k][j]);
	cout<<dis[1][n+1]<<endl;
	for(int i=1;i<=n+1;i++)
		if(dis[1][n+1]==dis[1][i]+dis[i][n+1])
			cout<<i<<" ";
	cout<<endl;
	return 0;
}