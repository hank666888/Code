#include <iostream>
using namespace std;

int n,m;

int h[310],G[310][310];

bool visited[310];

int max_c,max_h;

void dfs(int x){
	visited[x]=true;
	for(int i=1;i<=n;i++)
		if(G[x][i]&&!visited[i]){
			dfs(i);
		}
}

bool check(){
	for(int i=1;i<=n;i++)
		if(!visited[i])
			return false;
	return true;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		if(h[i]>max_h){
			max_c=i;
			max_h=h[i];
		}
	}
	for(int j=1;j<=m;j++){
		int u,v;
		cin>>u>>v;
		if(h[u]>h[v])
			G[u][v]=1;
		else if(h[u]<h[v])
			G[v][u]=1;
	}
	dfs(max_c);
	if(!check()){
		cout<<"Non\n";
	}
	else{
		cout<<"Oui, j'ai trouve la solution.\n"<<max_c<<"\n";
	}
	return 0;
}