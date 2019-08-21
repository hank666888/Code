#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
const int dir[8][2]={{-2,1},{2,1},{1,2},{1,-2},{-2,-1},{2,-1},{-1,2},{-1,-2}};

int n,m;

bool cango(int x,int y){
    if(x>=1&&y>=1&&x<=n&&y<=m)
        return true;
    return false;
}

struct E
{
    int x,y,step;
};

int sx,sy;
queue<E> q;

int ans[410][410];
bool vis[410][410];

void bfs(){
    E s;
    s.x=sx;
    s.y=sy;
    s.step=0;
    q.push(s);
    ans[sx][sy]=0;
    vis[sx][sy]=true;
    while(!q.empty()){
        E now=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int nx=now.x+dir[i][0],ny=now.y+dir[i][1];
            if(cango(nx,ny)&&!vis[nx][ny]){
                ans[nx][ny]=now.step+1;
                vis[nx][ny]=true;
                q.push((E){nx,ny,now.step+1});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    cin>>sx>>sy;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans[i][j]=-1;
    bfs();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%-5d",ans[i][j]);
        cout<<endl;
    }
    return 0;
}