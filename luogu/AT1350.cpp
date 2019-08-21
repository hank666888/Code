#include <iostream>
using namespace std;

char map[510][510];

int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

int n,m,sx,sy,fx,fy;

bool visited[510][510],flag;

void dfs(int x,int y){
	if(x==fx&&y==fy){
		return ;
	}
	if(!flag){
		visited[x][y]=true;
		for(int i=0;i<4;i++){
			int nx=x+dir[i][0],ny=y+dir[i][1];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&map[nx][ny]!='#'&&!visited[nx][ny]){
				dfs(nx,ny);
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>map[i][j];
			if(map[i][j]=='s')
				sx=i,sy=j;
			if(map[i][j]=='g')
				fx=i,fy=j;
		}
	dfs(sx,sy);
	if(visited[fx][fy])
		cout<<"No\n";
	else
		cout<<"Yes\n";
	return 0;
}