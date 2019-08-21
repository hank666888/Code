#include<iostream>
using namespace std;
int main()
{
    long long n,f[101];
    cin>>n;
    f[1]=1;
    for(int i=2;i<=n;i++)
        f[i]=f[i-1]*2+1;
    cout<<f[n]*2<<endl;
    return 0;
}