#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#define MAXN 110
#define INF 1e9
using namespace std;

struct point{
	int x,y;
};

point p[MAXN];

typedef pair<double,int> P;

int n,m;
struct edge{
	int to;
	double cost;
};
vector<edge> G[MAXN];
priority_queue< P, vector<P>, greater<P> > q;
double d[MAXN];

double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

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
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	cin>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back((edge){v,dis(p[u],p[v])});
		G[v].push_back((edge){u,dis(p[u],p[v])});
	}
	int s,t;
	cin>>s>>t;
	dijkstra(s);
	printf("%.2f\n", d[t]);
	return 0;
}