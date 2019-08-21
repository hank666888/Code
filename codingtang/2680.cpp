#include<iostream>
using namespace std;

const int MAXN=110;
const int INF =1e9;
int n,s,ans,start,ls[MAXN],ns[MAXN][2],a[MAXN][2][10];

//计算v的哪个端点与u相连
int checkdir(int u,int v){
    for(int i=1;i<=ns[v][0];i++){
        if(a[v][0][i]==u)
            return 0;
    }
    return 1;
}

//u表示当前搜索到的边的编号
//dir表示u这条边出去继续搜索的方向
void dfs(int u,int dir,int sum) {
    if(sum>=ans)
        return ;
    if(u==start&&sum>0){
        ans=min(ans,sum);
        return ;
    }
    sum+=ls[u];
    for(int i=1;i<=ns[u][dir];i++){
        int v=a[u][dir][i];
        dfs(v,1-checkdir(u,v),sum);
    }
}

int main(){
    cin>>n;
    ans=INF;
    for(int i=1;i<=n;i++){
        cin>>s;
        cin>>ls[s]>>ns[s][0]>>ns[s][1];
        for(int j=1;j<=ns[s][0];j++)
            cin>>a[s][0][j];
        for(int j=1;j<=ns[s][1];j++)
            cin>>a[s][1][j];
    }
    for(start=1;start<=n;start++)
        dfs(start,0,0);
    cout<<ans<<endl;
    return 0;
}
