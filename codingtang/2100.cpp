#include<iostream>
#include<algorithm>
using namespace std;

struct edge{
    int from,to,cost;
};
edge e[100010];

bool cmp(edge a,edge b){
    return a.cost<b.cost;
}

int n,m,ans,f[100010];

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
            ans=max(ans,e[i].cost);
        }
    }
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++)
        cin>>e[i].from>>e[i].to>>e[i].cost;
    sort(e+1,e+1+m,cmp);
    kruskal();
    cout<<n-1<<" "<<ans<<endl;
    return 0;
}
