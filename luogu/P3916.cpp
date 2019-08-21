#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

vector<int> G[100010];
int n,m;
int ans[1000010];

bool vis[1000010];

void dfs(int u,int d){
    if(ans[u])
        return ;
    ans[u]=d;
    for(int i=0;i<G[u].size();i++)
        dfs(G[u][i],d);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[v].push_back(u);
    }
    for(int i=n;i>=1;i--)
        dfs(i,i);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}