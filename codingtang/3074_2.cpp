#include<iostream>
using namespace std;

const int INF=1e9;
const int dir1[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const int dir2[8][2]={{-2,0},{2,0},{0,-2},{0,2},{1,-1},{-1,-1},{1,1},{-1,1}};\

int n,m;
int a[110][110];
int f[110][110];

bool vaild(int x,int y){
    if(x>=1&&x<=m&&y>=1&&y<=m)
        return true;
    return false;
}

void dfs(int x,int y,int cost){
    if(cost>=f[x][y])
        return ;
    f[x][y]=cost;
    if(x==m&&y==m)
        return ;
    for(int i=0;i<4;i++){
        int nx=x+dir1[i][0],ny=y+dir1[i][1];
        if(vaild(nx,ny)){
            if(a[nx][ny]>=0)
                dfs(nx,ny,(a[x][y]==a[nx][ny]?0:1)+cost);
            else if(nx==m&&ny==m)
                dfs(nx,ny,cost+2);
        }
    }
    for(int i=0;i<8;i++){
        int nx=x+dir2[i][0],ny=y+dir2[i][1];
        if(vaild(nx,ny)){
            if(a[nx][ny]>=0)
                dfs(nx,ny,(a[x][y]==a[nx][ny]?2:3)+cost);
        }
    }
}

int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++){
            a[i][j]=-1;
            f[i][j]=INF;
        }
    for(int i=1;i<=n;i++){
        int x,y,c;
        cin>>x>>y>>c;
        a[x][y]=c;
    }
    dfs(1,1,0);
    if(f[m][m]==INF)
        cout<<-1<<endl;
    else
        cout<<f[m][m]<<endl;
    return 0;
}
