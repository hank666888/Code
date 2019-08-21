#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

struct edge{
    int from,to;
    double cost;
};
edge e[250010];

bool cmp(edge a,edge b){
    return a.cost<b.cost;
}

struct point{
    int x,y;
};
point p[10010];

int n,m,k,f[1010];

double dist(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
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
    int cnt=0;
    for(int i=1;i<=m;i++)
        if(find(e[i].from)!=find(e[i].to)){
            f[find(e[i].to)]=find(e[i].from);
            cnt++;
            if(cnt==n-k){
                printf("%.2f\n",e[i].cost);
                break;
            }
        }
}

int main(){
    cin>>n>>k;
    init();
    for(int i=1;i<=n;i++)
        cin>>p[i].x>>p[i].y;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            m++;
            e[m].from=i;
            e[m].to=j;
            e[m].cost=dist(p[i],p[j]);
        }
    }
    sort(e+1,e+1+m,cmp);
    kruskal();
    return 0;
}