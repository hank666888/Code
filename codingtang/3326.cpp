#include<iostream>
using namespace std;

int n,t,x;
int a[110],b[110],c[110];
int f[1010][1010];

int main(){
    cin>>n>>t>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n;i++)
        for(int j=t;j>=b[i];j--)
            for(int k=x;k>=c[i];k--)
                f[j][k]=max(f[j][k],f[j-b[i]][k-c[i]]+a[i]);
    cout<<f[t][x]<<endl;
    return 0;
}
