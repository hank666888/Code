#include <iostream>
using namespace std;

long long G[1510][1510],n,m,d[1510];

bool used[1510];

long long max(long long a,long long b){
    if(a>b)
        return a;
    return b;
}

void dijkstra(){
    fill(d,d+1+n,0);
    fill(used,used+1+n,false);
    d[1]=0;
    while(true){
        int v=-1;
        for(int u=1;u<=n;u++)
            if(!used[u]&&(v==-1||d[u]>d[v]))
                v=u;
        if(v==-1)
            break;
        used[v]=true;
        for(int u=1;u<=n;u++)
            if(d[u]<d[v]+G[v][u])
                d[u]=d[v]+G[v][u];
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        G[u][v]=c;
    }
    dijkstra();
    cout<<d[n]<<endl;
    return 0;
}