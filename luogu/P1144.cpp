#include <iostream>
#include <vector>
#include <queue>
#define MAXN 1000010
#define INF 1e9
#define MOD 100003
using namespace std;

typedef pair<int,int> P;

struct edge{
	int to,cost;
};
std::vector<edge> G[MAXN];

int n,m,d[MAXN],ans[MAXN];

priority_queue<P, vector<P>, greater<P> > q;

void dijkstra(int s){
	fill(d,d+1+n,INF);
	d[s]=0;
	ans[s]=1;
	q.push(P(0,s));
	while(!q.empty()){
		P p=q.top();
		q.pop();
		int v=p.second;
		if(p.first>d[v])
			continue;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(d[e.to]==d[v]+e.cost){
				ans[e.to]=(ans[e.to]+ans[v])%MOD;
			}
			else if(d[e.to]>d[v]+e.cost){
				ans[e.to]=ans[v];
				d[e.to]=d[v]+e.cost;
				q.push(P(d[e.to],e.to));
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back((edge){v,1});
		G[v].push_back((edge){u,1});
	}
	dijkstra(1);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	return 0;
}