#include<iostream>
#include<queue>
using namespace std;
const int dir[4][2]={{-1,0},{0,1},{0,-1},{1,0}};

struct E
{
    int x,y,step;
};

int n;
char map[1010][1010];

bool vis[1010][1010];

int x1,x2,y1,y2;

queue<E> q;

bool cango(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=n&&map[x][y]=='0')
        return true;
    return false;
}

int bfs(){
    E s;
    s.x=x1;
    s.y=y1;
    s.step=0;
    vis[x1][y1]=true;
    q.push(s);
    while(!q.empty()){
        E now=q.front();
        q.pop();
        if(now.x==x2&&now.y==y2)
            return now.step;
        for(int i=0;i<4;i++){
            int nx=now.x+dir[i][0],ny=now.y+dir[i][1];
            if(cango(nx,ny)&&!vis[nx][ny]){
                vis[nx][ny]=true;
                q.push((E){nx,ny,now.step+1});
            }
        }
    }
    return 0;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>map[i][j];
    cin>>x1>>y1>>x2>>y2;
    cout<<bfs()<<endl;
    return 0;
}