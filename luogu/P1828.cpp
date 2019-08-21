#include <iostream>
#include <vector>
#include <queue>
#define MAXN 810
#define INF 1e9
using namespace std;

typedef pair<int,int> P;

struct edge{
	int to,cost;
};
std::vector<edge> G[MAXN];

int c,n,m,cow[510],ans=INF,d[MAXN];

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
	cin>>c>>n>>m;
	for(int i=1;i<=c;i++)
		cin>>cow[i];
	for(int i=1;i<=m;i++){
		int u,v,x;
		cin>>u>>v>>x;
		G[u].push_back((edge){v,x});
		G[v].push_back((edge){u,x});
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
		int sum=0;
		for(int j=1;j<=c;j++)
			sum+=d[cow[j]];
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}