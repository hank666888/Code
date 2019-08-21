#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
#define MAXN 110
using namespace std;

typedef pair<int,int> P;

struct edge{
    int to,cost;
};
vector<edge> G[110];

int n,d[MAXN];

priority_queue<P, vector<P>, greater<P> > q; 

int change(char c){
    if(c>='a'&&c<='z')
        return int(c-'a'+1);
    return int(c-'A'+27);
}

void dijkstra(int s){
    fill(d+1,d+1+MAXN,INF);
    d[s]=0;
    q.push(P(0,s));
    while(!q.empty()){
        P p=q.top();
        q.pop();
        int v=p.second;
        if(p.first>d[v])
            continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[v]+e.cost<d[e.to]){
                d[e.to]=d[v]+e.cost;
                q.push(P(d[e.to],e.to));
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char u,v;
        int c;
        cin>>u>>v;
        cin>>c;
        G[change(u)].push_back((edge){change(v),c});
        G[change(v)].push_back((edge){change(u),c});
    }
    dijkstra(change('Z'));
    int ans=INF;
    char ans_c;
    for(int i=change('A');i<=change('Y');i++)
        if(d[i]<ans){
            ans=d[i];
            ans_c=char(i-27+'A');
        }
    cout<<ans_c<<" "<<ans<<endl;
    return 0;
}