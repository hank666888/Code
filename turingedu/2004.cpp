#include<iostream>
#include<algorithm>
using namespace std;

struct edge{
    int from,to,cost;
};
edge es[200010];
int n,m,t[10010],f[10010];
long long ans;

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
    for(int i=1;i<=m;i++)
        if(find(es[i].from)!=find(es[i].to)){
            f[find(es[i].to)]=find(es[i].from);
            ans+=es[i].cost;
        }
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=n;i++)
        cin>>t[i];
    for(int i=1;i<=m;i++){
        cin>>es[i].from>>es[i].to>>es[i].cost;
        es[i].cost*=2;
        es[i].cost+=t[es[i].from]+t[es[i].to];
    }
    sort(es+1,es+1+m,cmp);
    kruskal();
    int ans2=1e9;
    for(int i=1;i<=n;i++)
        ans2=min(ans2,t[i]);
    cout<<ans+ans2<<endl;
    return 0;
}