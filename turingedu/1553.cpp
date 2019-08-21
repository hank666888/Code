#include<iostream>
#include<algorithm>
using namespace std;

long long n,a1[201],b1[201],a2[201],b2[201],x[201],y[201],a,b;
long long ans;

long long max_l(long long a,long long b){
    return a>b?a:b;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a1[i]>>b1[i]>>a2[i]>>b2[i];
        x[i]=a1[i];x[i+n]=a2[i];
        y[i]=b1[i];y[i+n]=b2[i];
    }
    cin>>a>>b;
    sort(x+1,x+1+n*2);
    sort(y+1,y+1+n*2);
    for(int i=1;i<=2*n-1;i++)
        for(int j=1;j<=2*n-1;j++){
            int cnt=0;
            for(int k=1;k<=n;k++)
            {
                if(a1[k]+a<=x[i] && b1[k]+b<=y[j] && a2[k]-a>=x[i+1] && b2[k]-b>=y[j+1])
                {
                    cnt++;
                }
            }
            ans=max_l(ans,cnt);
        }
    cout<<ans<<endl;
    return 0;
}
