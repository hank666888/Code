#include <iostream>
#include <vector>
#define INF 1e8
#define MAXN 10010
using namespace std;

int _max(int a,int b){
	return a>b?a:b;
}

int _min(int a,int b){
	return a<b?a:b;
}


struct edge
{
	int to,cost;
};

std::vector<edge> G[MAXN];

int n,m,s,t,d[MAXN];

bool used[MAXN];

void dijkstra(){
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
		for(int u=0;u<G[v].size();u++)
			d[G[v][u].to]=_min(d[G[v][u].to],_max(d[v],G[v][u].cost));
	}
}

int main(){
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		G[u].push_back((edge){v,c});
		G[v].push_back((edge){u,c});
	}
	dijkstra();
	cout<<d[t]<<endl;
	return 0;
}