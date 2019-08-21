#include <iostream>
#include <vector>
using namespace std;

std::vector<int> G[10010];

std::vector<int> rG[10010];

int d[10010];
int n,m;
int s,t;
bool visited[10010];
bool cant[10010];
bool used[10010];

void dfs(int x){
	visited[x]=true;
	for(int i=0;i<rG[x].size();i++)
		if(!visited[rG[x][i]]){
			dfs(rG[x][i]);
		}
}

void dijkstra(){
	fill(d,d+1+n,100000);
	fill(used,used+1+n,false);
	d[s]=0;
	while(true){
		int v=-1;
		for(int u=1;u<=n;u++)
			if(!used[u]&&((v==-1&&!cant[u]&&visited[u])||d[u]<d[v]))
				v=u;
		if(v==-1)
			break;
		used[v]=true;
		for(int u=0;u<G[v].size();u++)
			if(!cant[G[v][u]]&&visited[G[v][u]]&&d[G[v][u]]>d[v]+1)
				d[G[v][u]]=d[v]+1;
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		rG[v].push_back(u);
	}
	cin>>s>>t;
	dfs(t);
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			for(int j=0;j<rG[i].size();j++)
				cant[rG[i][j]]=true;
		}
	}
	if(!visited[s]||cant[s]){
		cout<<-1<<endl;
		return 0;
	}
	dijkstra();
	cout<<d[t]<<endl;
	return 0;
}