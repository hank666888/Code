#include <iostream>
#include <algorithm>
using namespace std;

struct edge
{
	int u,v,t;
};

edge E[100010];

bool cmp(edge a,edge b){
	return a.t<b.t;
}

int n,m;

int fa[100010];

void init(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
}

int find(int x){
	if(fa[x]!=x)
		fa[x]=find(fa[x]);
	return fa[x];
}

void unite(int x,int y){
	x=find(x),y=find(y);
	if(x==y)
		return ;
	n--;
	fa[x]=y;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>E[i].u>>E[i].v>>E[i].t;
	}
	sort(E+1,E+1+m,cmp);
	init();
	for(int i=1;i<=m;i++){
		unite(E[i].u,E[i].v);
		if(n==1){
			cout<<E[i].t<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}