#include<bits/stdc++.h>
using namespace std;
int V,M,n,v[110],m[110],e[110],f[500][500];
int main()
{
    scanf("%d%d",&V,&M);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&v[i],&m[i],&e[i]);
    for(int i=1;i<=n;i++)
        for(int j=V;j>=v[i];j--)
            for(int k=M;k>=m[i];k--)
                f[j][k]=max(f[j][k],f[j-v[i]][k-m[i]]+e[i]);
    printf("%d",f[V][M]);
    return 0;
}
