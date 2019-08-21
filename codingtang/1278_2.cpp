#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAXN 810
#define INF 1e9
using namespace std;

struct edge{
    int to,cost;
};
vector<edge> G[MAXN];
int d[MAXN],n,c,cow[MAXN],ans=INF;
bool exist[MAXN];
queue<int> q;
int p;

void spfa(int s){
    fill(d,d+1+p,INF);
    fill(exist,exist+1+p,false);
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
                    q.push(e.to);
                    exist[e.to]=true;
                }
            }
        }
    }
}

int main(){
    cin>>n>>p>>c;
    for(int i=1;i<=n;i++){
        cin>>cow[i];
    }
    for(int i=1;i<=c;i++){
        int x,y,z;
        cin>>x>>y>>z;
        G[x].push_back((edge){y,z});
        G[y].push_back((edge){x,z});
    }
    ans=INF;
    for(int i=1;i<=p;i++){
        spfa(i);
        int sum=0;
        for(int j=1;j<=n;j++){
            sum+=d[cow[j]];
        }
        if(sum<ans){
            ans=sum;
        }
    }
    cout<<ans<<endl;
    return 0;
}