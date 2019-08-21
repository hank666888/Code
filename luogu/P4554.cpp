#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 1000010
#define INF 1e9
using namespace std;

const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
typedef pair<int,int> P;

struct edge{
	int to,cost;
};
std::vector<edge> G[MAXN];

int n,m,x1,y1,x2,y2,d[MAXN];

priority_queue<P, vector<P>, greater<P> > q;

void dijkstra(int s){
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

char ma[510][510];

int oxy(int x,int y){
	return (x-1)*m+y;
}

int main(){
	while(cin>>n>>m,n||m){
		memset(ma,0,sizeof(ma));
		fill(d,d+1+n*m,INF);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>ma[i][j];
		cin>>x1>>y1>>x2>>y2;
		x1++,y1++,x2++,y2++;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				for(int k=0;k<4;k++){
					int nx=i+dir[k][0],ny=j+dir[k][1];
					if(nx>0&&ny>=0&&nx<=n&&ny<=m){
						if(ma[i][j]==ma[nx][ny]){
							G[oxy(i,j)].push_back((edge){oxy(nx,ny),0});
							G[oxy(nx,ny)].push_back((edge){oxy(i,j),0});
						}
						else{
							G[oxy(i,j)].push_back((edge){oxy(nx,ny),1});
							G[oxy(nx,ny)].push_back((edge){oxy(i,j),1});
						}
					}
				}
			}
		dijkstra(oxy(x1,y1));
		cout<<d[oxy(x2,y2)]<<endl;
		for(int i=1;i<=n*m;i++)
			while(!G[i].size())
				G[i].pop_back();
		cout<<endl;
	}
	return 0;
}