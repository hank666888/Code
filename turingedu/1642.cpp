#include <iostream>
#define INF 1e8
using namespace std;

int n,m;

long long d[1010],G[1010][1010];

bool used[1010];

void init(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            G[i][j]=INF;
}
void dijkstra(int s){
    fill(d,d+1+n,INF);
    fill(used,used+1+n,false);
    d[s]=0;
    while(true){
        int v=-1;
        for(int u=1;u<=n;u++)
            if(!used[u]&&(v==-1||d[u]<d[v]))
                v=u;
        if(v==-1)
            break;
        used[v]=true;
        for(int u=1;u<=n;u++)
            if(d[v]+G[v][u]<d[u]&&G[v][u]!=INF)
                d[u]=d[v]+G[v][u];
    }
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int u,v,c;
        int k;
        cin>>k;
        if(k==0){
            cin>>u>>v;
            dijkstra(u);
            if(d[v]==INF)
                cout<<-1<<endl;
            else
                cout<<d[v]<<endl;
        }
        else{
            cin>>u>>v>>c;
            if(c<G[u][v]){
                G[u][v]=G[v][u]=c;
            }
        }
    }
    return 0;
}