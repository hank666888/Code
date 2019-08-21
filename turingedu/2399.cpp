#include<iostream>
using namespace std;

const int MAXN=1010;

int G[MAXN][MAXN];
bool visited[MAXN];
int n,m;
int ans=1e9;

void hamCycle(int u,int t,int sum){
    if(sum>=ans)
        return ;
    if(t>n){
        ans=min(ans,sum+G[u][1]);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(G[u][i]&&!visited[i]){
            visited[i]=true;
            hamCycle(i,t+1,sum+G[u][i]);
            visited[i]=false;
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin>>G[i][j];
    }
    visited[1]=true;
    hamCycle(1,2,0);
    cout<<ans<<endl;
    return 0;
}