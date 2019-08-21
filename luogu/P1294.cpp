#include<iostream>
using namespace std;

int n,m;
int G[21][21];

int ans;
bool vis[21];


void dfs(int p,int dis){
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(G[p][i]&&!vis[i]){
            flag=true;
            vis[p]=true;
            dfs(i,dis+G[p][i]);
            vis[p]=false;
        }
    }
    if(!flag){
        ans=max(ans,dis);
        return ;
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,c;
        cin>>x>>y>>c;
        G[x][y]=c;
        G[y][x]=c;
    }
    for(int i=1;i<=n;i++)
        dfs(i,0);
    cout<<ans<<endl;
    return 0;
}