#include<iostream>
using namespace std;

int n,ans;

void dfs(int cur){
    if(cur==n){
        ans++;
        return ;
    }
    for(int i=1;i<=n;i++)
        dfs(cur+i);
}

int main(){
    cin>>n;
    dfs(0);
    cout<<ans<<endl;
    return 0;
}