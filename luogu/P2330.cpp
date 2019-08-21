#include<iostream>
#include<algorithm>
using namespace std;

struct edge{
    int from,to,cost;
};
edge es[100010];

bool cmp(edge a,edge b){
    return a.cost<b.cost;
}

int n,m,f[100010],ans;

void init(){
    for(int i=1;i<=n;i++)
        f[i]=i;
}

int find(int x){
    if(f[x]!=x)
        f[x]=find(f[x]);
    return f[x];
}

void kruskal(){
    for(int i=1;i<=m;i++){
        if(find(es[i].from)!=find(es[i].to)){
            f[find(es[i].to)]=find(es[i].from);
            ans=max(ans,es[i].cost);
        }
    }
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        es[i]=(edge){u,v,c};
    }
    sort(es+1,es+1+m,cmp);
    kruskal();
    cout<<n-1<<" "<<ans<<endl;
    return 0;
}