
#include<cstdio>
using namespace std;
const int mm=20000000;
bool f[mm];
int h[110];
int i,j,k,n,b,m;
int main()
{
	scanf("%d%d",&n,&b);
    for(m=i=0;i<n;++i)scanf("%d",&h[i]),m+=h[i];
    for(i=0;i<=m;++i)f[i]=0;
    f[0]=1;
    for(i=0;i<n;++i)
        for(j=m-h[i];j>=0;--j)
            if(f[j])f[j+h[i]]=1;
    for(i=b;i<=m;++i)
        if(f[i])break;
    printf("%d\n",i-b);
    return 0;
}