#include<iostream>
using namespace std;

const int MAXN=2000;
int G[MAXN][MAXN],ans[MAXN],cnt,n,m,du[MAXN],count;
int s1,s2;
int s;

void dfs(int u){
    for(int i=1;i<=n;i++){
        if(G[u][i]){
            G[u][i]--;
            G[i][u]--;
            dfs(i);
        }
    }
    ans[++cnt]=u;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        s=min(s,min(a,b));
        s1=a;
        s2=b;
        G[a][b]++;
        G[b][a]++;
        du[a]++;
        du[b]++;
    }
    int j;
    for(int i=1;i<=n;i++){
        if(du[i]%2==1){
            count++;
            if(count==1)
                j=i;
        }
    }
    if(n==1){
        cout<<min(s1,s2)<<endl<<max(s1,s2)<<endl;
        return 0;
    }
    if(count==0)
        dfs(1);
    else if(count==2)
        dfs(j);
    for(int i=cnt;i>=1;i--)
        cout<<ans[i]<<endl;
    cout<<endl;
    return 0;
}
