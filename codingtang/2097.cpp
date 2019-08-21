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

int n,G[110][110],m,f[100010],ans;

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
    cin>>n;
    init();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>G[i][j];
            if(i!=j){
                m++;
                e[m].from=i;
                e[m].to=j;
                e[m].cost=G[i][j];
            }
        }
    sort(e+1,e+1+m,cmp);
    kruskal();
    cout<<ans<<endl;
    return 0;
}
