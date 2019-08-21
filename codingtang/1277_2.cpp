#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=2010;

int n,m,x,y,z,a,b;
double d[MAXN],G[MAXN][MAXN];
bool used[MAXN];

void dijkstra(int s){
	fill(d+1,d+1+n,0);
	memset(used,false,sizeof(used));
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
			d[u]=max(d[u],d[v]*G[v][u]);
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		G[x][y]=G[y][x]=(100-z)/100.0;
	}
	cin>>a>>b;
	dijkstra(a);
	printf("%.8f\n", 100.0/d[b]);
	return 0;
}