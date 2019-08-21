#include<iostream>
using namespace std;

int n,m;
int landmine[51][51];
int dp[51][51];
int ans;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n-i+1;j++){
            cin>>landmine[i][j];
            dp[i][j]=landmine[i][j];
        }
    for(int i=2;i<=m;i++)
        for(int j=1;j<=n-i+1;j++)
            dp[i][j]+=max(dp[i-1][j],dp[i-1][j+1]);
    for(int j=1;j<=n-m+1;j++)
        ans=max(ans,dp[m][j]);
    cout<<ans<<endl;
    return 0;
}
