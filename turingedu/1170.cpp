#include<iostream>
using namespace std;
int a[500010]={0};
int main()
{
    long long n,k,i,t,j;
    double v;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>v>>t;
        for(j=1;j<=t;j++)
        {
            k=v*j;
            a[k]=!a[k];
        }
    }
    i=1;
    while(a[i]==0)
    {
        i++;
    }
    cout<<i;
    return 0;
}