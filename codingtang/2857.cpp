#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;

int a[maxn],n,m;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    int ans=0;
    for(int i=1;i<=m;i++)
        ans+=a[i];
    cout<<ans<<endl;
    return 0;
}
