#include<iostream>
#include<cstring>
#define MAXN 110
#define INF 1e9
using namespace std;

int n,G[MAXN][MAXN],mincost[MAXN];
bool used[MAXN];

int prim(){
    int ret=0;
    memset(used,false,sizeof(used));
    fill(mincost+1,mincost+1+n,INF);
    mincost[1]=0;
    while(true){
        int v=-1;
        for(int i=1;i<=n;i++)
            if(!used[i]&&(v==-1||mincost[i]<mincost[v]))
                v=i;
        if(v==-1)
            break;
        ret+=mincost[v];
        used[v]=true;
        for(int i=1;i<=n;i++)
            if(G[v][i]<mincost[i]&&!used[i])
                mincost[i]=G[v][i];
    }
    return ret;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>G[i][j];
    cout<<prim()<<endl;
    return 0;
}
