#include <iostream>
using namespace std;
long long m,s,t,dp[300001];
int main()
{
    cin>>m>>s>>t;
    for(int i=1;i<=t;i++)
        if(m>=10)
        {
            m-=10;
            dp[i]=dp[i-1]+60;
          }
          else
          {
            m+=4;
               dp[i]=dp[i-1];
          }
    for(int i=1;i<=t;i++)
    {
        dp[i]=max(dp[i],dp[i-1]+17);
        if(dp[i]>=s)
        {
          cout<<"Yes"<<endl<<i;
          return 0;
        }
    }
    cout<<"No"<<endl<<dp[t];
    return 0;
}
