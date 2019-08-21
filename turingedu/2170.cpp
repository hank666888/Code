#include <iostream>
#include <cmath>
using namespace std;

int a[31];

int n,s,ans;

int sum1(int k,int t){
    int tot=0;
    for(int i=k+1;i<=n;i++)
        t++,tot+=t;
    return tot;
}

int sum2(int k,int t){
    int tot=0;
    for(int i=k+1;i<=n;i++)
        t--,tot+=t;
    return tot;
}

void dfs(int t,int sum){
    if(t>n){
        if(sum==s)
            ans++;
        return ;
    }
    if(sum+sum1(t-1,a[t-1])<s||sum+sum2(t-1,a[t-1])>s){
        return ;
    }
    a[t]=a[t-1]-1;
    dfs(t+1,sum+a[t]);
    a[t]=a[t-1]+1;
    dfs(t+1,sum+a[t]);
}

int main(){
    cin>>n>>s;
    dfs(2,0);
    cout<<ans<<endl;
    return 0;
}