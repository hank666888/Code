#include<iostream>
#include<cmath>
#include<cstdio>
#define INF 1e9
#define MAX_V 110
using namespace std;

const int MAX_E=1e6;

struct point{
    int x,y;
};
point p[MAX_V];

double dist(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

struct edge{
    int from,to;
    double cost;
};

edge es[MAX_E];
double d[MAX_V];
int V,E,e;

void shortest_path(int s){
    for(int i=1;i<=V;i++)
        d[i]=INF;
    d[s]=0;
    while(true){
        bool update=false;
        for(int i=1;i<=e;i++){
            edge ed=es[i];
            if(d[ed.from]!=INF&&d[ed.from]+ed.cost<d[ed.to]){
                d[ed.to]=d[ed.from]+ed.cost;
                update=true;
            }
        }
        if(!update)
            break;
    }
}

int main()
{
    cin>>V;
    for(int i=1;i<=V;i++){
        cin>>p[i].x>>p[i].y;
    }
    cin>>E;
    for(int i=1;i<=E;i++){
        int u,v;
        cin>>u>>v;
        es[++e].from=u;
        es[e].to=v;
        es[e].cost=dist(p[u],p[v]);
        es[++e].from=v;
        es[e].to=u;
        es[e].cost=dist(p[u],p[v]);
    }
    int s,t;
    cin>>s>>t;
    shortest_path(s);
    printf("%.2f\n",d[t]);
    return 0;
}