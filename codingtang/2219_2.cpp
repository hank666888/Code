#include<iostream>
#include<cstring>
using namespace std;

const int MAXN=1010,INF=1e8;
int d[MAXN],n,m,G[MAXN][MAXN],del[MAXN][MAXN];
bool used[MAXN];

void init(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            G[i][j]=INF;
}

void dijkstra(int s){
	fill(d,d+n+1,INF);
	memset(used,false,sizeof(used));
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
			if(d[v]+G[v][u]<d[u])
				d[u]=d[v]+G[v][u];
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
    int dele;
    cin>>dele;
    for(int i=1;i<=dele;i++){
        int a,b;
        cin>>a>>b;
        del[a][b]=del[b][a]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(G[i][j]!=INF&&!del[i][j])
                G[i][j]=0;
        }
    }
    int s,t;
    cin>>s>>t;
    dijkstra(s);
    cout<<d[t]<<endl;
    return 0;
}