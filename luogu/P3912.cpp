#include<cstdio>

bool prime[100000005];

int main()
{
    int n,x,ans=0;
    scanf("%d",&n);
    for(int i=4;i<=n;i+=2){
        prime[i]=1;
        ans++;
    }
    for(int i=3;i*i<=n;i+=2)
        if(prime[i]==0)
            for(int j=i;j*i<=n;j+=2){
                if(prime[i*j]==0)
                    ans++;
                prime[i*j]=1;
            }
    printf("%d",n-ans-1);
    return 0;
}