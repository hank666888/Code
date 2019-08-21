#include<iostream>
#include<algorithm>
using namespace std;

struct edge{
    int from,to,cost;
};

bool cmp(edge a,edge b){
    return a.cost<b.cost;
}

edge e[500010];

int n,m,f[500010];

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
    init();
    for(int i=1;i<=m;i++){
        if(find(e[i].from)!=find(e[i].to)){
            f[find(e[i].to)]=find(e[i].from);
            ans+=e[i].cost;
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>e[i].from>>e[i].to>>e[i].cost;
    sort(e+1,e+1+m,cmp);
    kruskal();
    cout<<ans<<endl;
    return 0;
}