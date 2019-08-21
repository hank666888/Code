#include <iostream>
using namespace std;

int n,m;

int fa[1010];

void init(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
}

int find(int x){
	if(x!=fa[x])
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
	while(cin>>n>>m,n){
		init();
		int ans=0;
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			unite(x,y);
		}
		for(int i=1;i<=n;i++)
			if(fa[i]==i)
				ans++;
		cout<<ans-1<<endl;
	}
	return 0;
}