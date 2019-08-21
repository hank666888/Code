#include<iostream>
#include<cstring>
#define MAXN 310
#define INF 1e9
using namespace std;

int n,m,G[MAXN][MAXN],mincost[MAXN];
bool used[MAXN];

void init(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            G[i][j]=INF;
}

int prim(){
    memset(used,false,sizeof(used));
    fill(mincost+1,mincost+1+n,INF);
    int ret=0;
    mincost[1]=0;
    while(true){
        int v=-1;
        for(int i=1;i<=n;i++)
            if(!used[i]&&(v==-1||mincost[i]<mincost[v]))
                v=i;
        if(v==-1)
            break;
        used[v]=true;
        for(int i=1;i<=n;i++)
            if(G[v][i]<mincost[i]&&!used[i])
                mincost[i]=G[v][i];
    }
    for(int i=1;i<=n;i++)
        ret=max(ret,mincost[i]);
    return ret;
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v>>G[u][v];
        G[v][u]=G[u][v];
    }
    cout<<n-1<<" "<<prim();
    return 0;
}
