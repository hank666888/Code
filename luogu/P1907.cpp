#include <iostream>
#include <cmath>
#include <cstdio>
#define INF 1e8
using namespace std;

struct point
{
	double x,y;
};

point p[1010];

double G[1010][1010],d[1010];

int n,m;

bool used[1010];

double a,b;

double dist(point p1,point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

void init(){
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			G[i][j]=INF;
}

void dijkstra(){
	fill(d,d+2+n,INF);
	fill(used,used+2+n,false);
	d[0]=0;
	while(true){
		int v=-1;
		for(int u=0;u<=n+1;u++)
			if(!used[u]&&(v==-1||d[u]<d[v]))
				v=u;
		if(v==-1)
			break;
		used[v]=true;
		for(int u=0;u<=n+1;u++)
			if(d[v]+G[v][u]<d[u])
				d[u]=d[v]+G[v][u];
	}
}

int main(){
	cin>>a>>b;
	cin>>n;
	init();
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	int u,v;
	while(cin>>u>>v,u||v){
		G[u][v]=G[v][u]=dist(p[v],p[u])*b;;
	}
	cin>>p[0].x>>p[0].y;
	cin>>p[n+1].x>>p[n+1].y;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++){
			if(G[i][j]!=INF||i==j)
				continue;
			G[i][j]=G[j][i]=dist(p[i],p[j])*a;
		}
	dijkstra();
	printf("%.4f\n",d[n+1]);
	return 0;
}