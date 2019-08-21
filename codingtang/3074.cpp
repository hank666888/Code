#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f

int mx[4]={0,0,1,-1},my[4]={1,-1,0,0},m,n,vis[101][101],ans=INF,col[101][101],best[101][101];

void dfs(int x,int y,int cost,int magic)
{
    if(x==m&&y==m)
    {
        best[x][y]=min(best[x][y],cost);
        return;
    }
    if(cost>=best[x][y])
        return;
    best[x][y]=cost;
    for(int i=0;i<4;i++)
    {
        int xx=mx[i]+x;int yy=my[i]+y;
        int color=col[xx][yy];
        if(xx<1||yy<1||xx>m||yy>m)
            continue;
        if(vis[xx][yy])
            continue;
        if(col[xx][yy]==-1&&magic==0&&col[x][y]!=-1)
        {
            vis[xx][yy]=1;
            col[xx][yy]=col[x][y];
            dfs(xx,yy,cost+2,1);
            col[xx][yy]=color;
            vis[xx][yy]=0;
        }
        if(col[xx][yy]==col[x][y]&&col[x][y]!=-1)
        {
            vis[xx][yy]=1;
            dfs(xx,yy,cost,0);
            vis[xx][yy]=0;
        }
        if(col[xx][yy]!=-1&&col[x][y]!=-1&&col[xx][yy]!=col[x][y])
        {
            vis[xx][yy]=1;
            dfs(xx,yy,cost+1,0);
            vis[xx][yy]=0;
        }
    }
}

int main(){
    memset(col,-1,sizeof(col));
    memset(best,0x3f,sizeof(best));
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y,c;
       	cin>>x>>y>>c;
        col[x][y]=c;
    }
    dfs(1,1,0,0);
    if(best[m][m]!=INF)
        cout<<best[m][m];
    else
        cout<<-1;
    return 0;
}

