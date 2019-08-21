#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN=100010,INF=1e9;

typedef pair<int,int> P;

struct edge{
	int to,cost;
};

vector<edge> G[MAXN];
priority_queue<P,vector<P>,greater<P> > q;
int d[MAXN],n,m,st;

void dijkstra(int s){
	fill(d+1,d+1+n,INF);
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
			if(d[v]+e.cost<d[e.to]){
				d[e.to]=d[v]+e.cost;
				q.push(P(d[e.to],e.to));
			}
		}
	}
}

int main(){
	cin>>n>>m>>st;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		G[u].push_back((edge){v,c});
	}
	dijkstra(st);
	for(int i=1;i<=n;i++)
		cout<<d[i]<<" ";
	return 0;
}