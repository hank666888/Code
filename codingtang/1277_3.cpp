#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define MAXN 2010
using namespace std;

typedef pair<double,int> P;

struct edge
{
	int to;
	double cost;
};
std::vector<edge> G[MAXN];
int n,m;
priority_queue<P> q;
double d[MAXN];

void dijkstra(int s){
	d[s]=1;
	q.push(P(1.0,s));
	while(!q.empty()){
		P p=q.top();
		q.pop();
		int v=p.second;
		if(p.first<d[v])
			continue;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(d[e.to]<d[v]*e.cost){
				d[e.to]=d[v]*e.cost;
				q.push(P(d[e.to],e.to));
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		double z;
		cin>>x>>y>>z;
		z=(100-z)/100.0;
		G[x].push_back((edge){y,z});
		G[y].push_back((edge){x,z});
	}
	int s,t;
	cin>>s>>t;
	dijkstra(s);
	printf("%.8lf\n", 100.0/d[t]);
	return 0;
}