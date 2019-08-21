#include<iostream>
using namespace std;

int n,m;

int G[110][110],edge[110][110];

void init(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            edge[i][j]=1e8;
}

void floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(edge[i][k]!=1e8&&edge[k][j]!=1e8)
                    edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        G[u][v]=G[v][u]=c;
        edge[u][v]=edge[v][u]=0;
    }
    int l;
    cin>>l;
    for(int i=1;i<=l;i++){
        int u,v;
        cin>>u>>v;
        edge[u][v]=edge[v][u]=G[u][v];
    }
    int s,t;
    cin>>s>>t;
    floyd();
    cout<<edge[s][t]<<endl;
    return 0;
}