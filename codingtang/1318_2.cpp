#include <iostream>
using namespace std;

const int MAXN=20000;

int fa[MAXN+10],n,m,q;

void init(int n){
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
	fa[x]=y;
}

bool same(int x,int y){
	return find(x)==find(y);
}

int main(){
	cin>>n>>m;
	init(n);
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		unite(a,b);
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(same(x,y))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}