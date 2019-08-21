#include <cstdio>
#include <cmath>
#define INF 1e8
using namespace std;

int n,m;

struct Point{
	int x,y;
};

Point point[110];

double dis[110][110];

double dist(int x1,int y1,int x2,int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=INF;
}

void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
}

int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		point[i]=(Point){x,y};
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		dis[a][b]=dis[b][a]=dist(point[a].x,point[a].y,point[b].x,point[b].y);
	}
	int s,t;
	scanf("%d%d",&s,&t);
	floyd();
	printf("%.2f\n",dis[s][t]);
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%.2f ",dis[i][j]);
		printf("\n");
	}
	*/
	return 0;
}