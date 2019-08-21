#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=110;

int n,a[maxn],V;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    cin>>n>>V;
    V/=2;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    int ans=0;
    for(int i=1;i<=V;i++)
        ans+=a[i];
    cout<<ans<<endl;
    return 0;
}
