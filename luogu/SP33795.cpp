#include<iostream>
using namespace std;

int t;

int n,a[10010];
long long m;

long long ans;

long long max(long long a,long long b){
    if(a>b)
        return a;
    return b;
}

void dfs(int cur,long long v){
    if(v>m)
        return ;
    if(cur>n){
        ans=max(ans,v);
        return ;
    }
    dfs(cur+1,v+a[cur]);
    dfs(cur+1,v);
}

int main(){
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
