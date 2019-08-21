#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int delta[4][6] = {{2,-1,2,0,-1,0},{2,1,2,0,1,0},{2,0,2,-1,0,-1},{2,0,2,1,0,1}};
const int MAXW=45;
const int MAXH=105;

char a[2*MAXH+1][2*MAXW+1];
int vis[MAXH][MAXW];
int dis[MAXH][MAXW];

struct Point{
	int x,y;
};

int w,h,maxr;

bool legal(int x,int y){
	return x>=1&&x<=h&&y>=1&&y<=w;
}

void bfs(int x,int y){
	vis[x][y]=1;
	dis[x][y]=1;
	Point p;
	p.x=x;
	p.y=y;
	queue<Point> q;
	q.push(p);
	while(!q.empty()){
		p=q.front(); 
		q.pop();
		for(int i=0;i<4;i++){
			int wx=delta[i][0]*p.x+delta[i][1];
			int wy=delta[i][2]*p.y+delta[i][3];
			int px=p.x+delta[i][4];
			int py=p.y+delta[i][5];
			if(a[wx][wy]==' '&&legal(px, py)&&!vis[px][py]){ 
				vis[px][py]=vis[p.x][p.y]+1;
				if(vis[px][py]<dis[px][py]) 
					dis[px][py]=vis[px][py];
				Point v; 
				v.x=px;
				v.y=py;
				q.push(v);
			}
		}
	}
}

int main(){
	Point d[2];
	int dl = 0;
	scanf("%d%d",&w,&h); 
	getchar();
	for(int i=1;i<=2*h+1;i++){
		for(int j=1;j<=2*w+1;j++){
			a[i][j]=getchar();
			if(a[i][j]==' '){
				if(i==1){
					d[dl].x=1;
					d[dl++].y=j/2;
				}
				else if(i==2*h+1){
					d[dl].x=h; 
					d[dl++].y=j/2;
				}
				else if(j==1){
					d[dl].x=i/2;
					d[dl++].y=1;
				}
				else if(j==2*w+1){
					d[dl].x=i/2; 
					d[dl++].y=w;
				}
			}
		}
		getchar();
	}
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			dis[i][j]=MAXH*MAXW;
	bfs(d[0].x,d[0].y);
	if(dl>1){
		memset(vis,0,sizeof(vis));
		bfs(d[1].x,d[1].y);
	}
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			if(dis[i][j]>maxr) 
				maxr=dis[i][j];
	printf("%d\n",maxr);
	return 0;
}
