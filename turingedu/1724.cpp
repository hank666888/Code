#include<iostream>
#include<algorithm>
using namespace std;
 
long long n,a1[201],b1[201],a2[201],b2[201],x[201],y[201];
long long ans;
 
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a1[i]>>b1[i]>>a2[i]>>b2[i];
        x[i]=a1[i];x[i+n]=a2[i];
        y[i]=b1[i];y[i+n]=b2[i];
    }
    sort(x+1,x+1+n*2);
    sort(y+1,y+1+n*2);
    for(int i=1;i<=2*n-1;i++)
        for(int j=1;j<=2*n-1;j++)
            for(int k=1;k<=n;k++)
            {
                if(x[i]>=a1[k] && y[j]>=b1[k] && x[i+1]<=a2[k] && y[j+1]<=b2[k])
                {
                    ans+=(x[i+1]-x[i])*(y[j+1]-y[j]);
                    break;
                }
            }
    cout<<ans<<endl;
    return 0;
}