#include <iostream>
#include <vector>
#include <queue>
#define MAXN 50010
#define INF 1e9
using namespace std;

typedef pair<int,int> P;

struct edge{
	int to,cost;
};
vector<edge> G[MAXN];

int n,m,b,d[MAXN];

priority_queue<P, vector<P>, greater<P> > q;

void dijkstra(int s){
	fill(d,d+1+n,INF);
	d[s]=0;
	q.push(P(0,s));
	while(!q.empty()){
		P p=q.top();
		q.pop();
		int v=p.second;
		if(p.first>d[v])
			continue;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				q.push(P(d[e.to],e.to));
			}
		}
	}
}

int main(){
	cin>>n>>m>>b;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		G[u].push_back((edge){v,c});
		G[v].push_back((edge){u,c});
	}
	dijkstra(1);
	while(b--){
		int u,v;
		cin>>u>>v;
		cout<<d[u]+d[v]<<endl;
	}
	return 0;
}