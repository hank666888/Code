#include<iostream>
using namespace std;

int v[110],w[110],c[110],n,m,V;

int f[210][210];

int main(){
    cin>>V>>m>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i]>>w[i]>>c[i];
    for(int i=1;i<=n;i++)
        for(int j=V;j>=v[i];j--)
            for(int k=m;k>=w[i];k--)
                f[j][k]=max(f[j][k],f[j-v[i]][k-w[i]]+c[i]);
    cout<<f[V][m]<<endl;
    return 0;
}