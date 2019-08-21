#include <iostream>
using namespace std;

int fa[100010],fa2[100010];

int n,m;

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
	fa[x]=y;
}

int main(){
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++){
		int p,x,y;
		cin>>p>>x>>y;
		if(p==0)
			unite(x,y);
		else{
			if(fa2[x]==0)
				fa2[x]=find(y);
			else
				unite(y,fa2[x]);
			if(fa2[y]==0)
				fa2[y]=find(x);
			else
				unite(x,fa2[y]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(fa[i]==i)
			ans++;
	cout<<ans<<endl;
	return 0;
}