#include <iostream>
#include <vector>
#include <queue>
#define MAXN 100010
#define INF 1e6
using namespace std;

typedef pair<int,int> P;

struct edge
{
	int to,cost;
};
std::vector<edge> G[MAXN];

int n,m,x,d[MAXN],ans[MAXN],max_l;

priority_queue<P, vector<P>, greater<P> > q;

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
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				q.push(P(d[e.to],e.to));
			}
		}
	}
}

int main(){
	cin>>n>>m>>x;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		G[u].push_back((edge){v,c});
	}
	for(int i=1;i<=n;i++){
		if(i==x)
			continue;
		dijkstra(i);
		ans[i]+=d[x];
	}
	dijkstra(x);
	for(int i=1;i<=n;i++){
		if(i==x)
			continue;
		ans[i]+=d[i];
		max_l=max(ans[i],max_l);
	}
	cout<<max_l<<endl;
	return 0;
}