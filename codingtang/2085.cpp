#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int dir[12][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,2},{2,2},{2,-2},{-2,-2}};

struct cheese{
    int x,y;
    int step;
};

int x1,y1,x2,y2;
bool vis[110][110];

queue<cheese> q;

bool cango(int x,int y){
    if(x>=1&&x<=100&&y>=1&&y<=100)
        return true;
    return false;
}

int bfs(int x,int y){
    cheese p;
    p.x=x;
    p.y=y;
    p.step=0;
    q.push(p);
    vis[x][y]=true;
    while(!q.empty()){
        cheese now;
        now=q.front();
        q.pop();
        for(int i=0;i<12;i++){
            int nx=now.x+dir[i][0],ny=now.y+dir[i][1];
            if(cango(nx,ny)&&!vis[nx][ny]){
                if(nx==1&&ny==1)
                    return now.step+1;
                cheese pnow;
                pnow.x=nx;
                pnow.y=ny;
                pnow.step=now.step+1;
                vis[nx][ny]=true;
                q.push(pnow);
            }
        }
    }
}

int main(){
    cin>>x1>>y1>>x2>>y2;
    cout<<bfs(x1,y1)<<endl;
    memset(vis,0,sizeof(vis));
    while(!q.empty())
        q.pop();
    cout<<bfs(x2,y2)<<endl;
    return 0;
}
