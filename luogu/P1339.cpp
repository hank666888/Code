#include <iostream>
#define INF 1e8
#define MAXN 2510
using namespace std;

int n,m,s,t,G[MAXN][MAXN],d[MAXN];

bool used[MAXN];

void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			G[i][j]=INF;
}

void dijkstra(){
	fill(d,d+1+n,INF);
	fill(used,used+1+n,false);
	d[s]=0;
	while(true){
		int v=-1;
		for(int u=1;u<=n;u++)
			if(!used[u]&&(v==-1||d[u]<d[v]))
				v=u;
		if(v==-1)
			break;
		used[v]=true;
		for(int u=1;u<=n;u++)
			if(d[v]+G[v][u]<d[u])
				d[u]=d[v]+G[v][u];
	}
}


int main(){
	cin>>n>>m>>s>>t;
	init();
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		G[u][v]=G[v][u]=c;
	}
	dijkstra();
	cout<<d[t]<<endl;
	return 0;
}