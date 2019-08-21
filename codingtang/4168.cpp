#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int INF=1e9,mod=2147483648-1;

struct D{
    int p,ret;
};
D d[1010];
bool cmp(D a,D b){
    return a.ret<b.ret;
}

int n,m,G[1010][1010];
long long ans=1;
bool used[1010];

void init(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            G[i][j]=INF;
    for(int i=1;i<=n;i++)
        d[i].p=i,d[i].ret=INF;
}

void dijkstra(int s){
    memset(used,false,sizeof(used));
    d[s].ret=0;
    while(true){
        int v=-1;
        for(int u=1;u<=n;u++)
            if(!used[u]&&(v==-1||d[u].ret<d[v].ret))
                v=u;
        if(v==-1)
            break;
        used[v]=true;
        for(int u=1;u<=n;u++)
            if(d[v].ret+G[v][u]<d[u].ret)
                d[u].ret=d[v].ret+G[v][u];
    }
}

void solve(){
    sort(d+1,d+1+n,cmp);
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<i;j++){
            if(d[i].ret==d[j].ret+G[d[j].p][d[i].p])
                cnt++;
        }
        ans=(ans*cnt)%mod;
        if(ans==0)
            ans=1;
    }
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        G[u][v]=G[v][u]=c;
    }
    dijkstra(1);
    solve();
    cout<<ans<<endl;
    return 0;
}
