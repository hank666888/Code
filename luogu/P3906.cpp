#include <iostream>
#define INF 1e8
using namespace std;

int n,m,dis[110][110];

void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j)
				continue;
			dis[i][j]=INF;
		}
}

void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

int main(){
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		dis[u][v]=dis[v][u]=1;
	}
	floyd();
	int k;
	cin>>k;
	while(k--){
		int u,v;
		cin>>v>>u;
		for(int i=1;i<=n;i++)
			if(dis[v][i]+dis[i][u]==dis[v][u])
				cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}