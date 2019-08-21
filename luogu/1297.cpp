#include<iostream>
#include<cmath>
using namespace std;
long long f[1010],n;
bool is_prime(int a)
{
    for(int i=2;i<=sqrt(a);i++)
        if(a%i==0)
            return false;
    return true;
}
int main()
{
    cin>>n;
    int cnt=0,prime[1010];
    for(int i=2;i<=n;i++)
        if(is_prime(i))
            prime[++cnt]=i;
    f[0]=1;
    for(int i=1;i<=cnt;i++)
    {
        for(int j=prime[i];j<=n;j++)
            f[j]+=f[j-prime[i]];
    }
    f[0]=0;
    cout<<f[n];
    return 0;
}