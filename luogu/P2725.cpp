#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int w[110];
int f[10000010];
int n,m,t;
const int inf=1061109567;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    memset(f,inf,sizeof(f));
    f[0]=0;
    for(int max=1;;++max)
    {
        for(int i=1;i<=m;i++)
        {
            if(max>=w[i])
            {
                if(f[max]>f[max-w[i]]+1)
                    f[max]=f[max-w[i]]+1;
            }
        }
        if(f[max]==inf||f[max]>n)
        {
            printf("%d\n",max-1);
            break;
        }
    }
    return 0;
}