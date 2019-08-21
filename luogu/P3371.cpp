#include <iostream>
#include <vector>
using namespace std;

struct edge
{
	int to,cost;
};

const int INF=2147483647;

int n,m,s;

bool used[10010];

vector<edge> G[10010];

int d[10010];

void dijkstra(){
	fill(d,d+n+1,INF);
	fill(used,used+n+1,false);
	d[s]=0;
	while(true){
		int v=-1;
		for(int u=1;u<=n;u++)
			if(!used[u]&&(v==-1||d[u]<d[v]))
				v=u;
		if(v==-1)
			break;
		used[v]=true;
		for(int u=0;u<G[v].size();u++)
			if(d[v]+G[v][u].cost<d[G[v][u].to]&&d[v]!=INF)
				d[G[v][u].to]=d[v]+G[v][u].cost;
	}
}

int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		G[u].push_back((edge){v,c});
	}
	dijkstra();
	for(int i=1;i<=n;i++)
		cout<<d[i]<<" ";
	cout<<endl;
	return 0;
}