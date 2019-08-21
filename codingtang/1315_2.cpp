#include <iostream>
using namespace std;

int n,m,fa[10010];

int p,x,y,ans;

bool b[1010][1010];

void init(){
    for(int i=1;i<=n;i++)
        fa[i]=i;
}

int find(int x){
    if(fa[x]!=x)
        fa[x]=find(fa[x]);
    return fa[x];
}//路径压缩后的find

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)
        return ;
    fa[x]=y;
}

int main(){
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++){
		cin>>p>>x>>y;
		if(!p)
			unite(x,y);
		else{
			for(int j=1;j<=n;j++){
				if(b[x][j])
					unite(y,j);
				if(b[y][j])
					unite(x,j);
			}
			b[x][y]=b[y][x]=true;
		}
	}
	for(int i=1;i<=n;i++)
		if(fa[i]==i)
			ans++;
	cout<<ans<<endl;
	return 0;
}