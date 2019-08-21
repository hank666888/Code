#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define INF 1e9
using namespace std;

struct edge{
    int to,cost;
};
vector<edge> G[1010];

int n,m,x,ans[1010],max_dis,d[1010];
bool exist[1010];

queue<int> q;

void spfa(int s){
    fill(d,d+1+n,INF);
    memset(exist,false,sizeof(exist));
    d[s]=0;
    q.push(s);
    exist[s]=true;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        exist[v]=false;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                if(!exist[e.to]){
                    exist[e.to]=true;
                    q.push(e.to);
                }
            }
        }
    }
}

int main(){
    cin>>n>>m>>x;
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        G[u].push_back((edge){v,c});
    }
    for(int i=1;i<=n;i++){
        spfa(i);
        ans[i]+=d[x];
    }
    spfa(x);
    for(int i=1;i<=n;i++)
        max_dis=max(max_dis,ans[i]+d[i]);
    cout<<max_dis<<endl;
    return 0;
}