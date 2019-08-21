#include<iostream>
using namespace std;
int a[200010],n,f[200010],max_sum=-100000000;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        f[i]=max(f[i-1]+a[i],a[i]);
        if(f[i]>max_sum)
            max_sum=f[i];
    }
    cout<<max_sum;
    return 0;
}
