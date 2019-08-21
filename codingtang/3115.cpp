#include <iostream>
using namespace std;
long long ma[25][25],f[25][25],n,m,c,b,mx[10]={2,2,1,1,-2,-2,-1,-1},my[10]={-1,1,2,-2,1,-1,-2,2};
int main(){
    cin>>n>>m>>b>>c;
    ma[b][c]=1;
    for(int i=0;i<8;i++){
        if(b+mx[i]>=0&&c+my[i]>=0)
            ma[b+mx[i]][c+my[i]]=1;
    }
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        if(ma[i][0]==1)
            break;
        f[i][0]=1;
    }
    for(int i=1;i<=m;i++){
        if(ma[0][i]==1)
            break;
        f[0][i]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(ma[i][j]==1)
                f[i][j]=0;
            else
                f[i][j]=f[i-1][j]+f[i][j-1];
        }
    cout<<f[n][m]<<endl;
    return 0;
}
