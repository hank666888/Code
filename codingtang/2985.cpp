#include<iostream>
using namespace std;
long long f[1100];
int main()
{
    int i,j,t,n=0;
    cin>>t;
    for(i=1;i<=t;i++)
        n+=i;
    if(n%2==1)
    {
        cout<<0<<endl;
        return 0;
    }
    n/=2;
    f[0]=1;
    for(i=1;i<=t;i++)
        for(j=n;j>=i;j--)
            f[j]+=f[j-i];
    cout<<f[n]/2<<endl;
    return 0;
}
