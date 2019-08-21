#include <cstdio>
#include <cmath>
#include <iostream>
#define INF 1e8
using namespace std;

struct point
{
	int x,y;
};

point p[110];

double G[110][110],d[110];

bool used[110];

double dist(point p1,point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

int n,m,s,t;

void dijkstra(){
	fill(d,d+n+1,INF);
	fill(used,used+n+1,false);
	d[s]=0;
	while(true){
		int v=-1;
		for(int u=1;u<=n;u++){
			if(!used[u]&&(v==-1||d[u]<d[v]))
				v=u;
		}
		if(v==-1)
			break;
		used[v]=true;
		for(int u=1;u<=n;u++){
			if(G[u][v]+d[v]<d[u])
				d[u]=G[u][v]+d[v];
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			G[i][j]=INF;
	cin>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		G[u][v]=G[v][u]=dist(p[u],p[v]);
	}
	cin>>s>>t;
	dijkstra();
	printf("%.2f\n",d[t]);
	return 0;
}