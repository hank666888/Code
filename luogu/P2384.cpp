#include <iostream>
#define MAXN 1010
#define INF 1e5
using namespace std;

int n,m;

long long G[MAXN][MAXN],d[MAXN];

bool used[MAXN];

void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			G[i][j]=INF;
}

void dijkstra(){
	fill(d,d+1+n,INF);
	fill(used,used+1+n,false);
	d[1]=1;
	while(true){
		int v=-1;
		for(int u=1;u<=n;u++)
			if(!used[u]&&(v==-1||d[u]<d[v]))
				v=u;
		if(v==-1)
			break;
		used[v]=true;
		cout<<v<<endl;
		for(int u=1;u<=n;u++)
			if(d[v]*G[v][u]<d[u]&&G[v][u]!=INF){
				d[u]=d[v]*G[v][u];
				cout<<u<<" "<<d[u]<<endl;
			}
	}
}

int main(){
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v>>G[u][v];
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<G[i][j]<<" ";
		cout<<endl;
	}
	*/
	dijkstra();
	for(int i=1;i<=n;i++)
		cout<<d[i]<<endl;
	cout<<d[n]%9987<<endl;
	return 0;
}