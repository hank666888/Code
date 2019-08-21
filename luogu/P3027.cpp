#include<iostream>
using namespace std;

long long n,m,c[100010],v[100010],f[100010],ans;

long long max_c(long long a,long long b){
    return a>b?a:b;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        c[i]=b-a;
        v[i]=a;
    }
    for(int i=1;i<=n;i++)
        for(int j=v[i];j<=m;j++)
            f[j]=max_c(f[j],f[j-v[i]]+c[i]);
    for(int i=1;i<=m;i++)
        ans=max_c(ans,f[i]-i+m);
    cout<<ans<<endl;
    return 0;
}
