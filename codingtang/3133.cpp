#include<iostream>
using namespace std;

int n,v,a[31];
int f[20010];

int main(){
    cin>>v>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=v;j>=a[i];j--)
            f[j]=max(f[j],f[j-a[i]]+a[i]);
    cout<<v-f[v]<<endl;
    return 0;
}
