#include<cstdio>
int main()
{
    int n,k,s;
    scanf("%d",&n);
    k=0;
    s=0;
    while(s<n)
    {
        k++;
        s+=k;
    }
    if(k%2==1)
    printf("%d/%d\n",s-n+1,k+n-s);
    else
    printf("%d/%d\n",k+n-s,s-n+1);
    return 0;
}
