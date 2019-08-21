#include <iostream>
#include <cstdio>
#define MAXN 2010
using namespace std;

double G[MAXN][MAXN],d[MAXN];

int n,m,s,t;

bool used[MAXN];

void dijkstra(){
	fill(used,used+1+n,false);
	d[s]=1;
	while(true){
		int v=-1;
		for(int u=1;u<=n;u++)
			if(!used[u]&&(v==-1||d[u]>d[v]))
				v=u;
		if(v==-1)
			break;
		used[v]=true;
		for(int u=1;u<=n;u++)
			if(d[v]*G[u][v]>d[u])
				d[u]=d[v]*G[u][v];
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		scanf("%lf",&G[v][u]);
		G[u][v]=G[v][u]=(100-G[v][u])/100.0;
	}
	cin>>s>>t;
	dijkstra();
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%.8lf ",G[i][j]);
		printf("\n");
	}
	*/
	printf("%.8lf\n",100/d[t]);
	return 0;
}