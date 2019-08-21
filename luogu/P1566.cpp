#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a[110],n,ans,now[4];
bool vis[110];

void dfs(int cur,int pos){
    if(cur==3){
        if(now[1]+now[2]==now[3])
            ans++;
        return ;
    }
    for(int i=pos+1;i<=n;i++){
        if(!vis[i]){
            now[cur+1]=a[i];
            vis[i]=true;
            dfs(cur+1,i);
            vis[i]=false;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ans=0;
        memset(vis,false,sizeof(vis));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        dfs(0,0);
        cout<<ans<<endl;
    }
    return 0;
}
