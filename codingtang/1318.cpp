#include<iostream>

using namespace std;

int fa[100010];
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

bool same(int x,int y){
    return find(x)==find(y);
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        unite(x,y);
    }
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(same(x,y))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}