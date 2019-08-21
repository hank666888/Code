#include<iostream>
#include<algorithm>
using namespace std;

struct edge{
    int u,v,c;
};
edge es[10010];
bool cmp(edge a,edge b){
    return a.c<b.c;
}

int n,m,fa[10010];

void init(){
    for(int i=1;i<=n;i++)
        fa[i]=i;
}

int find(int x){
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)
        return ;
    fa[x]=y;
}

bool same(int x,int y){
    return find(x)==find(y);
}

int kruskal(){
    int ret=0;
    sort(es+1,es+1+m,cmp);
    for(int i=1;i<=m;i++){
        if(!same(es[i].u,es[i].v)){
            ret=max(ret,es[i].c);
            unite(es[i].u,es[i].v);
        }
    }
    return ret;
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++)
        cin>>es[i].u>>es[i].v>>es[i].c;
    cout<<n-1<<" "<<kruskal()<<endl;
    return 0;
}
