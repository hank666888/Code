#include<iostream>
using namespace std;

int n,m,ans;

void dfs(int step,int t,int first){
    if(step==m){
        if(t==first)
            ans++;
        return ;
    }
    if(t==1)
        dfs(step+1,t+1,first),dfs(step+1,n,first);
    else if(t==n)
        dfs(step+1,1,first),dfs(step+1,t-1,first);
    else
        dfs(step+1,t+1,first),dfs(step+1,t-1,first);
}

int main(){
    cin>>n>>m;
    dfs(0,1,1);
    cout<<ans<<endl;
    return 0;
}