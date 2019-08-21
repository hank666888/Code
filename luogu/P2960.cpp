#include<iostream>
#include<queue>
using namespace std;

const int dir[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

struct node{
    int y,x,step;
};

int n,m,sx,sy;
char map[110][110];
bool vis[110][110];
queue<node> q;

int bfs(int y,int x){
    node first=(node){y,x,0};
    q.push(first);
    vis[y][x]=true;
    int ans=0;
    while(!q.empty()){
        node now=q.front();
        q.pop();
        ans=now.step;
        for(int i=0;i<8;i++){
            int nx=now.x+dir[i][0],ny=now.y+dir[i][1];
            if(map[ny][nx]=='.'&&!vis[ny][nx]){
                vis[ny][nx]=true;
                q.push((node){ny,nx,now.step+1});
            }
        }
    }
    return ans;
}

int main(){
    cin>>n>>m>>sx>>sy;
    for(int i=m;i>=1;i--)
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    cout<<bfs(sy,sx)<<endl;
    return 0;
}
