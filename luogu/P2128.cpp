#include<iostream>
using namespace std;

int n,m;

bool G[1010][1010];

int boat[451];

bool vis[451];

int ans;

void dfs(int x,int sum){
    for(int i=1;i<=n;i++){
        if(G[x][i]&&!vis[i]){
            vis[x]=true;
            dfs(i,sum+boat[x]);
            vis[x]=false;
        }
    }
    ans=max(ans,sum+boat[x]);
    return ;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>boat[i];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        G[u][v]=G[v][u]=true;
    }
    for(int i=1;i<=n;i++){
        dfs(i,0);
    }
    cout<<ans<<endl;
    return 0;
}