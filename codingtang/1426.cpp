#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN=100010;
const int MOD=10007;

int n,m,ans;
long long number[MAXN],color[MAXN];
long long sum[MAXN][2],sum_id[MAXN][2],sum_n[MAXN][2],count[MAXN][2];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>number[i];
    for(int i=1;i<=n;i++)
        cin>>color[i];
    for(int i=1;i<=n;i++){
        count[color[i]][i%2]++;
        sum_id[color[i]][i%2]=(sum_id[color[i]][i%2]+i)%MOD;
        sum_n[color[i]][i%2]=(sum_n[color[i]][i%2]+number[i])%MOD;
        sum[color[i]][i%2]=(sum[color[i]][i%2]+(i*number[i])%MOD)%MOD;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<=1;j++){
            long long tmp;
            tmp=(((count[i][j]-2)*sum[i][j])%MOD+(sum_id[i][j]*sum_n[i][j])%MOD)%MOD;
            ans=(ans+tmp)%MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}
