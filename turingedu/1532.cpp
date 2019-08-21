#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct edge{
    int from,to,cost;
};
edge e[100010];

bool cmp(edge a,edge b){
    return a.cost<b.cost;
}

int a[110][110],n,m,f[100010],c;

long long ans;

int point(int x,int y){
    return (x-1)*m+y;
}

void init(){
    for(int i=1;i<=n*m;i++)
        f[i]=i;
}

int find(int x){
    if(f[x]!=x)
        f[x]=find(f[x]);
    return f[x];
}

void kruskal(){
    for(int i=1;i<=c;i++)
        if(find(e[i].from)!=find(e[i].to)){
            f[find(e[i].to)]=find(e[i].from);
            ans+=e[i].cost;
        }
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=m-1;j++){
            c++;
            e[c].from=point(i,j);
            e[c].to=point(i,j+1);
            e[c].cost=abs(a[i][j]-a[i][j+1]);
            c++;
            e[c].from=point(i,j);
            e[c].to=point(i+1,j);
            e[c].cost=abs(a[i][j]-a[i+1][j]);
        }
    for(int i=1;i<=n-1;i++){
        c++;
        e[c].from=point(i,m);
        e[c].to=point(i+1,m);
        e[c].cost=abs(a[i][m]-a[i+1][m]);
    }
    for(int j=1;j<=m-1;j++){
        c++;
        e[c].from=point(n,j);
        e[c].to=point(n,j+1);
        e[c].cost=abs(a[n][j]-a[n][j+1]);
    }
    sort(e+1,e+1+c,cmp);
    kruskal();
    cout<<ans<<endl;
    return 0;
}