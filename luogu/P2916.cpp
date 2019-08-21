#include<iostream>
#include<algorithm>
using namespace std;

struct edge{
    int from,to,cost;
};
edge e[100010];
int f[10010],n,m,c[10010],ans,min_c=1e9;

bool cmp(edge a,edge b){
    return a.cost<b.cost;
}

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
        if(find(e[i].from)!=find(e[i].to)){
            f[find(e[i].to)]=find(e[i].from);
            ans+=e[i].cost;
        }
    }
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=n;i++){
        cin>>c[i];
        min_c=min(min_c,c[i]);
    }
    for(int i=1;i<=m;i++){
        cin>>e[i].from>>e[i].to>>e[i].cost;
        e[i].cost=e[i].cost*2+c[e[i].from]+c[e[i].to];
    }
    sort(e+1,e+1+m,cmp);
    kruskal();
    cout<<ans+min_c<<endl;
    return 0;
}
