#include<iostream>
#include<algorithm>
using namespace std;

struct edge{
    int from,to,cost;
};
edge e[10010];

bool cmp(edge a,edge b){
    return a.cost<b.cost;
}

int n,m,f[10010],c;

long long ans;

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
    for(int i=1;i<=c;i++){
        if(find(e[i].from)!=find(e[i].to)){
            f[find(e[i].to)]=find(e[i].from);
            ans+=e[i].cost;
        }
    }
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int p,u,v,w;
        cin>>p>>u>>v>>w;
        if(p==1){
            f[find(v)]=find(u);
            ans+=w;
        }
        else{
            c++;
            e[c].from=u;
            e[c].to=v;
            e[c].cost=w;
        }
    }
    sort(e+1,e+1+c,cmp);
    kruskal();
    cout<<ans<<endl;
    return 0;
}